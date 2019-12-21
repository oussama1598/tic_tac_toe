#ifndef GAME_H
#define GAME_H

#include "imports.h"

GtkWidget *game_page_window;
GtkWidget *game_canvas;

unsigned int game_matrix[3][3];
int canvas_width;
int canvas_height;

void game_page_init();
void show_game_page();
void clear_game();

// signals
void on_draw(GtkWidget *canvas, cairo_t *cr, gpointer user_data);
void on_game_canvas_mouse_pressed(GtkWidget *widget, GdkEventButton *event, gpointer user_data);

#endif
