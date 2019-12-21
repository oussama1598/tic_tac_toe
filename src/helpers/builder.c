#include "builder.h"

void app_init()
{
    default_path = "/home/red-scule/Desktop/projects/c_projects/tic_tac_toe/src/";

    css_file = "css/style.css";

    templates_length = TEMPLATES_LENGTH;

    templates[0] = "pages/main/main.glade";
    templates[1] = "pages/signin/signin.glade";
    templates[2] = "pages/game/game.glade";

    load_templates();
    load_stylesheet();

    init_windows();
}

void load_templates()
{
    builder = gtk_builder_new();
    css_provider = gtk_css_provider_new();

    for (int i = 0; i < templates_length; i++)
    {
        gtk_builder_add_from_file(builder, join_strings(default_path, templates[i]), NULL);
    }
}

void load_stylesheet()
{
    gtk_css_provider_load_from_path(css_provider, join_strings(default_path, css_file), NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
}

void init_windows()
{
    signin_init();
    game_page_init();
}
