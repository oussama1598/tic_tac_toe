#ifndef BUILDER_H
#define BUILDER_H

#include "imports.h"

#define TEMPLATES_LENGTH 3

GtkBuilder *builder;
GtkCssProvider *css_provider;

// default path
char *default_path;

// templates
char *templates[TEMPLATES_LENGTH];
int templates_length;

// css file
char *css_file;

void app_init();
void load_templates();
void load_stylesheet();
void init_windows();

#endif
