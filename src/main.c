#include "imports.h"

int main(int argc, char **argv)
{
    gtk_init(&argc, &argv);

    app_init();

    gtk_builder_connect_signals(builder, NULL);

    show_game_page();

    g_object_unref(builder); // frees the pointer builder
    gtk_main();

    return 0;
}
