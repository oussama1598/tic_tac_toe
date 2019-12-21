#include "signin_page.h"

void show_signin_page()
{
    signin_page_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_widget_show_all(signin_page_window);
}

void close_signin_page()
{
    gtk_widget_destroy(signin_page_window);
}
