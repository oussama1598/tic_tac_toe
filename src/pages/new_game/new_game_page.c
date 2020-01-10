#include "new_game_page.h"

void new_game_page_init()
{
    new_game_page_window = GTK_WIDGET(gtk_builder_get_object(builder, "new_game_page"));

    // init widgets
    new_game_ai_button = GTK_BUTTON(gtk_builder_get_object(builder, "new_game_ai"));
    new_game_random_button = GTK_BUTTON(gtk_builder_get_object(builder, "new_game_random"));
    new_game_back_button = GTK_BUTTON(gtk_builder_get_object(builder, "new_game_back_button"));

    // init signals
    g_signal_connect(new_game_page_window, "destroy", G_CALLBACK(on_destroy), NULL);
    g_signal_connect(new_game_ai_button, "clicked", G_CALLBACK(on_new_game_choose_button_clicked), GINT_TO_POINTER(AGAINST_AI));
    g_signal_connect(new_game_random_button, "clicked", G_CALLBACK(on_new_game_choose_button_clicked), GINT_TO_POINTER(AGAINST_RADNOM));
    g_signal_connect(new_game_back_button, "clicked", G_CALLBACK(on_new_game_back_button_clicked), NULL);
}

void show_new_game_page()
{
    gtk_widget_show(new_game_page_window);
}

void close_new_game_page()
{
    gtk_widget_hide(new_game_page_window);
}

// signals
void on_new_game_choose_button_clicked(GtkButton *button, gpointer user_data)
{
    close_new_game_page();
    show_game_page(GPOINTER_TO_INT(user_data), 0);
}

void on_new_game_back_button_clicked(GtkButton *button, gpointer user_data)
{
    close_new_game_page();
    show_main_page();
}
