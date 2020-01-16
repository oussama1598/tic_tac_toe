#include "about_page.h"

/**
 * Inits the about page.
*/
void about_page_init()
{
    about_page_window = GTK_WIDGET(gtk_builder_get_object(builder, "about_page"));
    about_canvas = GTK_WIDGET(gtk_builder_get_object(builder, "about_canvas"));
    about_back_button = GTK_BUTTON(gtk_builder_get_object(builder, "about_back_button"));

    // init signals
    g_signal_connect(about_page_window, "destroy", G_CALLBACK(on_destroy), NULL);
    g_signal_connect(about_back_button, "clicked", G_CALLBACK(on_about_back_button_clicked), NULL);
    g_signal_connect(about_canvas, "draw", G_CALLBACK(on_about_canvas_draw), NULL);
}

/**
 * A callback function that gets called when frame has to be drawn.
 * 
 * @return 1 if the animation should be stopped, 0 if not.
*/
int on_animate()
{
    if (animation_direction == ANIMATION_FORWARD)
        scale += 0.1;
    else
        scale -= 0.1;

    if (scale > 2)
        animation_direction = ANIMATION_BACKWARD;
    else if (scale <= 0)
        animation_direction = ANIMATION_FORWARD;

    gtk_widget_queue_draw_area(about_canvas, 0, 0, about_canvas_width, about_canvas_height);

    return !animate;
}

/**
 * Shows the about page.
*/
void show_about_page()
{
    animation_direction = ANIMATION_FORWARD;
    scale = 0;
    animate = 0;

    gtk_widget_show(about_page_window);

    g_timeout_add(50, G_SOURCE_FUNC(on_animate), NULL);
}

/**
 * Closes the about page.
*/
void close_about_page()
{
    animate = 1;

    gtk_widget_hide(about_page_window);
}

/**
 * A callback function that gets called when the about back button is pressed.
*/
void on_about_back_button_clicked(GtkButton *button, gpointer user_data)
{
    close_about_page();
    show_main_page();
}

/**
 * A callback function that gets called when canvas want to draw to the screen.
*/
void on_about_canvas_draw(GtkWidget *canvas, cairo_t *cr, gpointer user_data)
{
    guint width, height;
    GtkStyleContext *context;

    context = gtk_widget_get_style_context(canvas);

    width = gtk_widget_get_allocated_width(canvas);
    height = gtk_widget_get_allocated_height(canvas);

    about_canvas_width = width;
    about_canvas_height = height;

    gtk_render_background(context, cr, 0, 0, width, height);

    cairo_set_source_rgb(cr, 221 / 255.0, 63 / 255.0, 63 / 255.0);

    cairo_translate(cr, width / 2, height / 2);
    cairo_rotate(cr, G_PI);
    cairo_scale(cr, 5 + scale, 5 + scale);

    int num_points = 100;
    float dt = (2 * G_PI / num_points);
    float x = 16 * pow(sin(dt), 3);
    float y = 13 * cos(dt) - 5 * cos(2 * dt) - 2 * cos(3 * dt) - cos(4 * dt);

    cairo_move_to(cr, x, y);

    for (float t = dt; t <= 2 * G_PI; t += dt)
    {
        x = 16 * pow(sin(t), 3);
        y = 13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t);

        cairo_line_to(cr, x, y);
    }

    cairo_close_path(cr);

    cairo_fill(cr);
}
