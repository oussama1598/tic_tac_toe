#include "game.h"

void game_page_init()
{
    // seed the random generator
    srand(time(NULL));

    flags = GTK_DIALOG_MODAL;

    game_page_window = GTK_WIDGET(gtk_builder_get_object(builder, "game_page"));

    // init widgets
    game_canvas = GTK_WIDGET(gtk_builder_get_object(builder, "game_canvas"));
    game_restart_button = GTK_MENU_ITEM(gtk_builder_get_object(builder, "game_restart_button"));
    game_quit_button = GTK_MENU_ITEM(gtk_builder_get_object(builder, "game_quit_button"));
    game_save_button = GTK_MENU_ITEM(gtk_builder_get_object(builder, "game_save_button"));
    game_history_button = GTK_MENU_ITEM(gtk_builder_get_object(builder, "game_history_button"));
    game_message_box = GTK_LABEL(gtk_builder_get_object(builder, "game_message_box"));

    gtk_widget_add_events(game_canvas, GDK_BUTTON_PRESS_MASK);

    // init signals
    g_signal_connect(game_page_window, "destroy", G_CALLBACK(on_destroy), NULL);
    g_signal_connect(game_canvas, "draw", G_CALLBACK(on_draw), NULL);
    g_signal_connect(game_canvas, "button-press-event", G_CALLBACK(on_game_canvas_mouse_pressed), NULL);
    g_signal_connect(game_restart_button, "activate", G_CALLBACK(on_game_restart_button_clicked), NULL);
    g_signal_connect(game_quit_button, "activate", G_CALLBACK(on_game_quit_button_clicked), NULL);
    g_signal_connect(game_save_button, "activate", G_CALLBACK(on_save_button_clicked), NULL);
    g_signal_connect(game_history_button, "activate", G_CALLBACK(on_game_history_button_clicked), NULL);
}

void show_game_page(int ai_type, int did_back)
{
    gtk_widget_show(game_page_window);

    if (!did_back)
    {
        against_ai_type = ai_type;
        init_game();
    }
}

void close_game_page()
{
    gtk_widget_hide(game_page_window);
}

void init_game()
{
    // gets defined a random sign
    player_sign = (rand() % 2) + 1;

    clear_game();
}

void clear_game()
{
    // reseting all the game variables
    game_finished = 0;
    game_line_win = -1;
    game_column_win = -1;

    turns_played = 0;

    // reseting the board

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            game_matrix[i][j] = 0;
            game_history[i][j] = 0;
        }

    // reshowing the signe message
    char message[50];
    sprintf(message, "Your signe is %c", player_sign == X_SIGN ? 'x' : 'o');

    set_message(message);
}

void load_game_save(char *ai_type, char *saved_player_sign, char *board_state)
{
    // TODO: set player sign
    player_sign = atoi(saved_player_sign);
    against_ai_type = atoi(ai_type);

    clear_game();

    // this block of code copies the board state to a new string
    // in order for the board state to no be touched by the strtok
    char board_state_copy[strlen(board_state) + 1];

    strcpy(board_state_copy, board_state);

    char *board_state_rest = board_state_copy;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            char *cell_state = strtok_r(board_state_rest, "-", &board_state_rest);

            game_matrix[i][j] = atoi(strtok(cell_state, ";"));
            game_history[i][j] = atoi(strtok(NULL, ";"));

            if (game_matrix[i][j] == O_SIGN || game_matrix[i][j] == X_SIGN)
            {
                turns_played += 1;
            }
        }
}

void save_game()
{
    if (game_finished)
    {
        show_dialog(GTK_MESSAGE_ERROR, GTK_BUTTONS_OK, "Can't save after the game is finished.");
        return;
    }

    char game_state[200] = {'\0'};

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            char cell_data[5] = "-0";

            sprintf(cell_data, "%d;%d-", game_matrix[i][j], game_history[i][j]);

            strcat(game_state, cell_data);
        }

    if (add_save(game_state, against_ai_type, player_sign, 0) < 0)
    {
        if (show_dialog(
                GTK_MESSAGE_WARNING,
                GTK_BUTTONS_YES_NO,
                "The saves limit (3) is exceded. Do you want to replace the oldest save ?") == GTK_RESPONSE_YES)
        {
            add_save(game_state, against_ai_type, player_sign, 1);

            show_dialog(GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Game saved successfly.");
        }
    }
    else
    {
        show_dialog(GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Game saved successfly.");
    }
}

void set_message(const char *str)
{
    gtk_label_set_text(game_message_box, str);
}

int is_board_full()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            if (game_matrix[i][j] == 0)
                return 0;
        }

    return 1;
}

void game_check_if_win()
{
    int winner_player = -1;

    game_line_win = -1;
    game_column_win = -1;

    // check lines
    for (int i = 0; i < 3; i++)
        if (game_matrix[i][0] != 0 && game_matrix[i][0] == game_matrix[i][1] && game_matrix[i][1] == game_matrix[i][2])
        {
            // win
            game_line_win = i;

            winner_player = game_matrix[i][0] == player_sign ? PLAYER_WON : AI_WON;
        }

    // check columns
    for (int j = 0; j < 3; j++)
        if (game_matrix[0][j] != 0 && game_matrix[0][j] == game_matrix[1][j] && game_matrix[1][j] == game_matrix[2][j])
        {
            // win
            game_column_win = j;

            winner_player = game_matrix[0][j] == player_sign ? PLAYER_WON : AI_WON;
        }

    if (game_matrix[0][0] != 0 && game_matrix[0][0] == game_matrix[1][1] && game_matrix[1][1] == game_matrix[2][2])
    {
        // win
        game_line_win = 0;
        game_column_win = 1;

        winner_player = game_matrix[0][0] == player_sign ? PLAYER_WON : AI_WON;
    }

    if (game_matrix[0][2] != 0 && game_matrix[0][2] == game_matrix[1][1] && game_matrix[1][1] == game_matrix[2][0])
    {
        // win
        game_line_win = 1;
        game_column_win = 0;

        winner_player = game_matrix[0][2] == player_sign ? PLAYER_WON : AI_WON;
    }

    if (winner_player != -1)
    {
        char message[50];
        sprintf(message, "%s", winner_player == PLAYER_WON ? "You Win" : "The Ai wins");

        set_message(message);

        game_finished = 1;

        if (winner_player == PLAYER_WON)
        {
            score += AGAINST_AI ? 50 : 10;

            update_score();
        }
    }

    if (winner_player == -1 && is_board_full())
    {
        char message[50];
        sprintf(message, "%s", "No one wins, its a tie.");

        set_message(message);
        game_finished = 1;
    }
}

void redraw_game_canvas()
{
    gtk_widget_queue_draw_area(game_canvas, 0, 0, canvas_width, canvas_height);
}

void on_game_canvas_mouse_pressed(GtkWidget *widget, GdkEventButton *event, gpointer user_data)
{
    int x = event->x;
    int y = event->y;

    int cell_height = (canvas_height - 3) / 3;
    int cell_width = (canvas_width - 3) / 3;

    int cell_index_x = x / cell_width;
    int cell_index_y = y / cell_height;

    if (game_matrix[cell_index_y][cell_index_x] == 0 && !game_finished)
    {
        game_matrix[cell_index_y][cell_index_x] = player_sign;
        game_history[cell_index_y][cell_index_x] = ++turns_played;

        game_check_if_win();

        if (!game_finished)
        {
            if (against_ai_type == AGAINST_RADNOM)
                random_ai_play_next_move();
            else if (against_ai_type == AGAINST_AI)
                minimax_alphabeta_ai_play_next_move();

            game_check_if_win();
        }

        redraw_game_canvas();
    }
}

void on_game_restart_button_clicked(GtkMenuItem *button, gpointer user_data)
{
    clear_game();

    redraw_game_canvas();
}

void on_game_quit_button_clicked(GtkMenuItem *button, gpointer user_data)
{
    close_game_page();
    show_main_page();
}

void on_save_button_clicked(GtkMenuItem *button, gpointer user_data)
{
    save_game();
}

void on_game_history_button_clicked(GtkMenuItem *button, gpointer user_data)
{
    close_game_page();
    show_history_page();
}

void on_draw(GtkWidget *canvas, cairo_t *cr, gpointer user_data)
{
    guint width, height;
    GdkRGBA color;
    GtkStyleContext *context;

    context = gtk_widget_get_style_context(canvas);

    width = gtk_widget_get_allocated_width(canvas);
    height = gtk_widget_get_allocated_height(canvas);

    canvas_width = width;
    canvas_height = height;

    gtk_render_background(context, cr, 0, 0, width, height);

    float cell_height = (height - 3) / 3;
    float cell_width = (width - 3) / 3;

    for (int i = 1; i < 3; i++)
    {
        cairo_rectangle(cr, 0, cell_height * i, width, 1);
        cairo_rectangle(cr, cell_width * i, 0, 1, height);
    }

    cairo_rectangle(cr, 0, canvas_height - 1, canvas_width, 1);

    gtk_style_context_get_color(context,
                                gtk_style_context_get_state(context),
                                &color);
    gdk_cairo_set_source_rgba(cr, &color);

    cairo_fill(cr);

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            if (game_matrix[i][j] == O_SIGN)
            {
                float x = (cell_width * (j + 1)) - (cell_width / 2);
                float y = (cell_height * (i + 1)) - (cell_height / 2);

                float radius = (MIN(cell_height, cell_width) - 20) / 2.0;

                cairo_arc(cr, x, y, radius, 0, 2 * G_PI);
                cairo_stroke(cr);
            }
            else if (game_matrix[i][j] == X_SIGN)
            {
                int offset = 25;
                float x = cell_width * j + offset;
                float y = cell_height * i + offset;

                cairo_move_to(cr, x, y);
                cairo_line_to(cr, x + cell_width - (2 * offset), y + cell_height - (2 * offset));
                cairo_close_path(cr);

                cairo_move_to(cr, x + cell_width - (2 * offset), y);
                cairo_line_to(cr, x, y + cell_height - (2 * offset));
                cairo_stroke(cr);
            }
        }

    if (game_line_win != -1 && game_column_win != -1)
    {
        float x = canvas_width * game_line_win;
        float xto = canvas_width * game_column_win;

        cairo_move_to(cr, x, 0);
        cairo_line_to(cr, xto, canvas_height);
        cairo_close_path(cr);
        cairo_stroke(cr);
    }
    else
    {

        if (game_line_win != -1)
        {
            float y = (cell_height * (game_line_win + 1)) - (cell_height / 2);

            cairo_rectangle(cr, 0, y, canvas_width, 2);
            cairo_fill(cr);
        }

        if (game_column_win != -1)
        {
            float x = (cell_width * (game_column_win + 1)) - (cell_width / 2);

            cairo_rectangle(cr, x, 0, 2, canvas_height);
            cairo_fill(cr);
        }
    }
}
