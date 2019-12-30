#include "history_page.h"

void history_page_init()
{
    history_page_window = GTK_WIDGET(gtk_builder_get_object(builder, "history_page"));
}

void show_history_page()
{
    gtk_widget_show(history_page_window);
}

void close_history_page()
{
    gtk_widget_hide(history_page_window);
}
