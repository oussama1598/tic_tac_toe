#ifndef GAME_H
#define GAME_H

#include "imports.h"
#define PLAYER_WON 1
#define AI_WON 2

GtkWidget *game_page_window;
GtkWidget *game_canvas;
GtkWidget *game_restart_button;
GtkWidget *game_quit_button;

unsigned int game_matrix[3][3];
int canvas_width;
int canvas_height;

int game_finished;
int player_sign;
int against_ai_type;
int game_line_win;
int game_column_win;

void game_page_init();
void show_game_page();
void close_game_page();
void init_game();
void game_check_if_win();
void clear_game();
void redraw_game_canvas();

// signals
void on_draw(GtkWidget *canvas, cairo_t *cr, gpointer user_data);
void on_game_canvas_mouse_pressed(GtkWidget *widget, GdkEventButton *event, gpointer user_data);
void on_game_restart_button_clicked(GtkWidget *button, gpointer user_data);
void on_game_quit_button_clicked(GtkWidget *button, gpointer user_data);

#endif
