#ifndef BUILDER_H
#define BUILDER_H

#include "imports.h"

typedef struct template
{
    char *path;
    void (*init_fn)();
}
template;

GtkBuilder *builder;
GtkCssProvider *css_provider;

// default path
char *default_path;

// templates
template *templates;
int last_template_index;
int templates_length;

// css file
char *css_file;

void app_init();
void config_templates(int size, char *style_path);
void add_template(template template_data);
void load_templates();
void load_stylesheet();

// global methods
gint show_dialog(GtkMessageType type, GtkButtonsType buttons, const char *message);

// global signals
void on_destroy(GtkWidget *widget, gpointer user_data);

#endif
