#ifndef ABOUT_PAGE_H
#define ABOUT_PAGE_H

#include "imports.h"

GtkWidget *about_page_window;
GtkWidget *about_canvas;

int about_closed;
int forward_reverse;
float scale;
int about_canvas_width;
int about_canvas_height;

void about_page_init();
void show_about_page();
void close_about_page();

void on_about_canvas_draw(GtkWidget *canvas, cairo_t *cr, gpointer user_data);

#endif
