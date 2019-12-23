#include "imports.h"

int main(int argc, char **argv)
{
    gtk_init(&argc, &argv);

    // init the data
    load_data();

    // init the app visualy
    app_init();

    // show the login page
    show_signin_page();

    g_object_unref(builder); // frees the pointer builder
    gtk_main();              // enter the main loop

    return 0;
}
