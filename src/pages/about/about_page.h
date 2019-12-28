#ifndef ABOUT_PAGE_H
#define ABOUT_PAGE_H

#include "imports.h"

#define ANIMATION_FORWARD 1
#define ANIMATION_BACKWARD 0

GtkWidget *about_page_window;
GtkWidget *about_canvas;
GtkButton *about_back_button;

int animate;
int animation_direction;
float scale;
int about_canvas_width;
int about_canvas_height;

void about_page_init();
void show_about_page();
void close_about_page();

void on_about_back_button_clicked(GtkButton *button, gpointer user_data);
void on_about_canvas_draw(GtkWidget *canvas, cairo_t *cr, gpointer user_data);

#endif
