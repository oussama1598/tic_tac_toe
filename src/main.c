#include "imports.h"
#include "main_page.h"
#include "signin_page.h"

static void
activate(GtkApplication *app,
         gpointer user_data)
{
    show_main_page(app);
}

int main(int argc, char **argv)
{
    GtkApplication *app;

    app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    return 0;
}
