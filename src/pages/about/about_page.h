#ifndef ABOUT_PAGE_H
#define ABOUT_PAGE_H

#include "imports.h"

#define ANIMATION_FORWARD 1
#define ANIMATION_BACKWARD 0

/**
 * Points to the about page window.
*/
GtkWidget *about_page_window;
/**
 * Points to the about canvas.
*/
GtkWidget *about_canvas;
/**
 * Points to the about back button.
*/
GtkButton *about_back_button;

/**
 * A boolean that holds the state of the animation. 
*/
int animate;
/**
 * The animation's direction, forward or backward.
*/
int animation_direction;
/**
 * The scale of the heart.
*/
float scale;
/**
 * The width of the about canvas.
*/
int about_canvas_width;
/**
 * The height of the about canvas.
*/
int about_canvas_height;

void about_page_init();
void show_about_page();
void close_about_page();

void on_about_back_button_clicked(GtkButton *button, gpointer user_data);
void on_about_canvas_draw(GtkWidget *canvas, cairo_t *cr, gpointer user_data);

#endif
