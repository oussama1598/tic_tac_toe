#ifndef BUILDER_H
#define BUILDER_H

#include "imports.h"

/**
 * A structure that will contain the template's data.
*/
typedef struct template
{
    /**
     * The template's path.
    */
    char *path;
    /**
     * The template's init function.
    */
    void (*init_fn)();
}
template;

/**
 * An instance of the gtk's builder.
*/
GtkBuilder *builder;
/**
 * An instance of the css provider.
*/
GtkCssProvider *css_provider;

/**
 * The default parent directory for all the templates.
*/
char *default_path;

/**
 * A list that contains all the templates data of type {@link template}.
*/
template *templates;
/**
 * This variable holds the last template index.
*/
int last_template_index;
/**
 * The {@link templates} list length.
*/
int templates_length;

/**
 * the css's file path;
*/
char *css_file;

void app_init();
void config_templates(int size, char *style_path);
void add_template(template template_data);
void load_templates();
void load_stylesheet();

gint show_dialog(GtkMessageType type, GtkButtonsType buttons, const char *message);

void on_destroy(GtkWidget *widget, gpointer user_data);

#endif
