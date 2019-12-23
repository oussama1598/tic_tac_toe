#include "game.h"

void game_page_init()
{
    // seed the random generator
    srand(time(NULL));

    game_page_window = GTK_WIDGET(gtk_builder_get_object(builder, "game_page"));

    // init widgets
    game_canvas = GTK_WIDGET(gtk_builder_get_object(builder, "game_canvas"));
    game_restart_button = GTK_WIDGET(gtk_builder_get_object(builder, "game_restart_button"));
    // game_quit_button = GTK_BUTTON(gtk_builder_get_object(builder, "game_restart_button"));

    gtk_widget_add_events(game_canvas, GDK_BUTTON_PRESS_MASK);

    // init signals
    g_signal_connect(game_page_window, "destroy", G_CALLBACK(on_destroy), NULL);
    g_signal_connect(game_canvas, "draw", G_CALLBACK(on_draw), NULL);
    g_signal_connect(game_canvas, "button-press-event", G_CALLBACK(on_game_canvas_mouse_pressed), NULL);
    g_signal_connect(game_restart_button, "activate", G_CALLBACK(on_game_restart_button_clicked), NULL);
}

void show_game_page()
{
    gtk_widget_show(game_page_window);

    init_game();
}

void init_game()
{
    // gets defined a random sign
    player_sign = (rand() % 2) + 1;

    clear_game();
}

void clear_game()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            game_matrix[i][j] = 0;
}

void redraw_game_canvas()
{
    gtk_widget_queue_draw_area(game_canvas, 0, 0, canvas_width, canvas_height);
}

void on_game_restart_button_clicked(GtkWidget *button, gpointer user_data)
{
    clear_game();

    redraw_game_canvas();
}

void on_game_canvas_mouse_pressed(GtkWidget *widget, GdkEventButton *event, gpointer user_data)
{
    int x = event->x;
    int y = event->y;

    int cell_height = (canvas_height - 3) / 3;
    int cell_width = (canvas_width - 3) / 3;

    int cell_index_x = x / cell_width;
    int cell_index_y = y / cell_height;

    game_matrix[cell_index_y][cell_index_x] = player_sign;

    redraw_game_canvas();
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

    gtk_style_context_get_color(context,
                                gtk_style_context_get_state(context),
                                &color);
    gdk_cairo_set_source_rgba(cr, &color);

    cairo_fill(cr);

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            if (game_matrix[i][j] == 1)
            {
                float x = (cell_width * (j + 1)) - (cell_width / 2);
                float y = (cell_height * (i + 1)) - (cell_height / 2);

                float radius = (MIN(cell_height, cell_width) - 20) / 2.0;

                cairo_arc(cr, x, y, radius, 0, 2 * G_PI);
                cairo_stroke(cr);
            }
            else if (game_matrix[i][j] == 2)
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
}
