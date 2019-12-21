#include "signin_page.h"

void signin_init()
{
    signin_page_window = GTK_WIDGET(gtk_builder_get_object(builder, "signin_page"));

    // init widgets
    signin_button = GTK_BUTTON(gtk_builder_get_object(builder, "signin_button"));
    signin_username_input = GTK_ENTRY(gtk_builder_get_object(builder, "signin_username_input"));
    signin_password_input = GTK_ENTRY(gtk_builder_get_object(builder, "signin_password_input"));
    signin_error = GTK_LABEL(gtk_builder_get_object(builder, "signin_error"));

    // init signals
    g_signal_connect(signin_button, "clicked", G_CALLBACK(on_signin_button_clicked), NULL);
}

void show_signin_page()
{
    gtk_widget_show(signin_page_window);
}

void close_signin_page()
{
    gtk_widget_destroy(signin_page_window);
}

void on_signin_button_clicked(GtkButton *button, gpointer user_data)
{
    // gtk_entry_set_text(signin_username_input, "ok");
    show_game_page();
}
