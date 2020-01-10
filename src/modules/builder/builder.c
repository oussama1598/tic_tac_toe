#include "builder.h"

void app_init()
{
    default_path = "/home/red-scule/Desktop/projects/c_projects/tic_tac_toe/src/";

    load_templates();
    load_stylesheet();
}

void config_templates(int size, char *style_path)
{
    css_file = style_path;

    templates_length = size;
    templates = malloc(sizeof(template) * size);
    last_template_index = -1;
}

void add_template(template template_data)
{
    last_template_index += 1;

    templates[last_template_index] = template_data;
}

void load_templates()
{
    builder = gtk_builder_new();

    for (int i = 0; i < templates_length; i++)
    {
        gtk_builder_add_from_file(builder, join_strings(default_path, templates[i].path), NULL);

        (*templates[i].init_fn)();
    }
}

void load_stylesheet()
{
    css_provider = gtk_css_provider_new();

    gtk_css_provider_load_from_path(css_provider, join_strings(default_path, css_file), NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
}

// global signals
void on_destroy(GtkWidget *widget, gpointer user_data)
{
    gtk_main_quit();

    // TODO: to be moved from here
    free(accounts);
    free(saves);
    free(scores);
}
