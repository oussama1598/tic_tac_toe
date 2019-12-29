#include "load_game_page.h"

void load_game_page_init()
{
    load_game_page_window = GTK_WIDGET(gtk_builder_get_object(builder, "load_game_page"));
    load_game_back_button = GTK_BUTTON(gtk_builder_get_object(builder, "load_game_back_button"));
    load_game_select_button = GTK_BUTTON(gtk_builder_get_object(builder, "load_game_select_button"));

    load_game_option1 = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, "load_game_option1"));
    load_game_option2 = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, "load_game_option2"));
    load_game_option3 = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, "load_game_option3"));

    load_game_option1_label = GTK_LABEL(gtk_builder_get_object(builder, "load_game_option1_label"));
    load_game_option2_label = GTK_LABEL(gtk_builder_get_object(builder, "load_game_option2_label"));
    load_game_option3_label = GTK_LABEL(gtk_builder_get_object(builder, "load_game_option3_label"));

    // init signals
    g_signal_connect(load_game_page_window, "destroy", G_CALLBACK(on_destroy), NULL);
    g_signal_connect(load_game_back_button, "clicked", G_CALLBACK(on_load_game_back_button_clicked), NULL);
    g_signal_connect(load_game_select_button, "clicked", G_CALLBACK(on_load_game_select_button_clicked), NULL);
}

void show_load_game_page()
{
    clear_and_disable_all_options();
    render_saves_selection();
    enable_disable_load_button();

    gtk_widget_show(load_game_page_window);
}

void close_load_game_page()
{
    gtk_widget_hide(load_game_page_window);
}

void clear_and_disable_all_options()
{
    gtk_label_set_text(load_game_option1_label, "Empty Slot");
    gtk_label_set_text(load_game_option2_label, "Empty Slot");
    gtk_label_set_text(load_game_option3_label, "Empty Slot");

    gtk_widget_set_sensitive(GTK_WIDGET(load_game_option1), 0);
    gtk_widget_set_sensitive(GTK_WIDGET(load_game_option2), 0);
    gtk_widget_set_sensitive(GTK_WIDGET(load_game_option3), 0);
}

void render_radio_button(int id, char *text_to_render)
{
    switch (id)
    {
    case 0:
        gtk_label_set_text(load_game_option1_label, text_to_render);
        gtk_widget_set_sensitive(GTK_WIDGET(load_game_option1), 1);
        break;
    case 1:
        gtk_label_set_text(load_game_option2_label, text_to_render);
        gtk_widget_set_sensitive(GTK_WIDGET(load_game_option2), 1);
        break;
    case 2:
        gtk_label_set_text(load_game_option3_label, text_to_render);
        gtk_widget_set_sensitive(GTK_WIDGET(load_game_option3), 1);
        break;
    }
}

void enable_disable_load_button()
{
    gtk_widget_set_sensitive(GTK_WIDGET(load_game_select_button), saves_length > 0);
}

void render_saves_selection()
{
    for (int i = 0; i < saves_length; i++)
    {
        save_data savedata = saves[i];

        time_t timenum = (time_t)strtol(savedata.timestamp, NULL, 10);

        char buffer[26];
        struct tm *tm_info;

        tm_info = localtime(&timenum);

        strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);

        render_radio_button(i, buffer);
    }
}

void on_load_game_back_button_clicked(GtkButton *button, gpointer user_data)
{
    close_load_game_page();
    show_main_page();
}

void on_load_game_select_button_clicked(GtkButton *button, gpointer user_data)
{
    int selected_save_id = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(load_game_option1)) * 0 +
                           gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(load_game_option2)) +
                           gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(load_game_option3)) * 2;

    g_print("%d", selected_save_id);
}
