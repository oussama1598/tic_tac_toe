#include "main_page.h"

void show_main_page(GtkApplication *app)
{
    main_page_window = gtk_application_window_new(app);

    gtk_application_add_window(app, main_page_window);

    // gtk_widget_show_all(main_page_window);
}
