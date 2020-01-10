#include "history_page.h"

void history_page_init()
{
    history_page_window = GTK_WIDGET(gtk_builder_get_object(builder, "history_page"));

    history_back_button = GTK_BUTTON(gtk_builder_get_object(builder, "history_back_button"));
    history_canvas = GTK_WIDGET(gtk_builder_get_object(builder, "history_canvas"));

    // init signals
    g_signal_connect(history_page_window, "destroy", G_CALLBACK(on_destroy), NULL);
    g_signal_connect(history_canvas, "draw", G_CALLBACK(on_history_canvas_draw), NULL);
    g_signal_connect(history_back_button, "clicked", G_CALLBACK(on_history_back_button_clicked), NULL);
}

void show_history_page()
{
    gtk_widget_show(history_page_window);
}

void close_history_page()
{
    gtk_widget_hide(history_page_window);
}

void on_history_back_button_clicked(GtkButton *button, gpointer user_data)
{
    close_history_page();
    show_game_page(0, 1);
}

void on_history_canvas_draw(GtkWidget *canvas, cairo_t *cr, gpointer user_data)
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

                cairo_move_to(cr, x + radius, y);
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

            if (game_matrix[i][j] == O_SIGN || game_matrix[i][j] == X_SIGN)
            {
                float offset = 13;
                float text_x = (j + 1) * cell_height - offset;
                float text_y = (i + 1) * cell_width - offset;
                char play_number[5];

                sprintf(play_number, "%d", game_history[i][j]);

                cairo_move_to(cr, text_x, text_y);
                cairo_show_text(cr, play_number);
                cairo_close_path(cr);
            }
        }
}
