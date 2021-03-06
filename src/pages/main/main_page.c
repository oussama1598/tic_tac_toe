#include "main_page.h"

/**
 * Inits the main page.
*/
void main_page_init()
{
    main_page_window = GTK_WIDGET(gtk_builder_get_object(builder, "main_page"));
    new_game_button = GTK_BUTTON(gtk_builder_get_object(builder, "new_game_button"));
    load_game_button = GTK_BUTTON(gtk_builder_get_object(builder, "load_game_button"));
    score_button = GTK_BUTTON(gtk_builder_get_object(builder, "score_button"));
    about_button = GTK_BUTTON(gtk_builder_get_object(builder, "about_button"));
    signout_button = GTK_BUTTON(gtk_builder_get_object(builder, "signout_button"));

    // init signals
    g_signal_connect(main_page_window, "destroy", G_CALLBACK(on_destroy), NULL);
    g_signal_connect(new_game_button, "clicked", G_CALLBACK(on_new_game_button_clicked), NULL);
    g_signal_connect(load_game_button, "clicked", G_CALLBACK(on_load_game_button_clicked), NULL);
    g_signal_connect(score_button, "clicked", G_CALLBACK(on_score_button_clicked), NULL);
    g_signal_connect(about_button, "clicked", G_CALLBACK(on_about_button_clicked), NULL);
    g_signal_connect(signout_button, "clicked", G_CALLBACK(on_signout_button_clicked), NULL);
}

/**
 * Shows the main page.
*/
void show_main_page()
{
    gtk_widget_show(main_page_window);
}

/**
 * Closes the main page.
*/
void close_main_page()
{
    gtk_widget_hide(main_page_window);
}

/**
 * A callback function that gets called when the new game back button is pressed.
*/
void on_new_game_button_clicked(GtkButton *button, gpointer user_data)
{
    close_main_page();
    show_new_game_page();
}
/**
 * A callback function that gets called when the load game back button is pressed.
*/
void on_load_game_button_clicked(GtkButton *button, gpointer user_data)
{
    close_main_page();
    show_load_game_page();
}
/**
 * A callback function that gets called when the score button is pressed.
*/
void on_score_button_clicked(GtkButton *button, gpointer user_data)
{
    close_main_page();
    show_scores_page();
}
/**
 * A callback function that gets called when the about button is pressed.
*/
void on_about_button_clicked(GtkButton *button, gpointer user_data)
{
    close_main_page();
    show_about_page();
}
/**
 * A callback function that gets called when the signout button is pressed.
*/
void on_signout_button_clicked(GtkButton *button, gpointer user_data)
{
    close_main_page();
    show_signin_page();
}
