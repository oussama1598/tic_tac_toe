#include "main_page.h"

void show_main_page()
{
    main_page_window = GTK_WIDGET(gtk_builder_get_object(builder, "main_page"));

    gtk_widget_show(main_page_window);
}
