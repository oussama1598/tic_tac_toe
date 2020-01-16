#ifndef HISTORY_PAGE_H
#define HISTORY_PAGE_H

#include "imports.h"

/**
 * Points to the history page window.
*/
GtkWidget *history_page_window;
/**
 * Points to the back button.
*/
GtkButton *history_back_button;
/**
 * Points to the history canvas.
*/
GtkWidget *history_canvas;

void history_page_init();
void show_history_page();
void close_history_page();

// signals
void on_history_canvas_draw(GtkWidget *canvas, cairo_t *cr, gpointer user_data);
void on_history_back_button_clicked(GtkButton *button, gpointer user_data);

#endif
