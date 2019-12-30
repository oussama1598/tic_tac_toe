#ifndef GAME_H
#define GAME_H

#include "imports.h"
#define PLAYER_WON 1
#define AI_WON 2
#define NO_MOVES_LEFT -1
#define O_SIGN 1
#define X_SIGN 2

GtkWidget *game_page_window;
GtkWidget *game_save_dialog;
GtkWidget *game_canvas;
GtkWidget *game_restart_button;
GtkWidget *game_quit_button;
GtkWidget *game_save_button;
GtkLabel *game_message_box;

GtkDialogFlags flags;

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
void clear_game();
void set_message(const char *str);
void game_check_if_win(int isTie);
void redraw_game_canvas();

// signals
void on_draw(GtkWidget *canvas, cairo_t *cr, gpointer user_data);
void on_game_canvas_mouse_pressed(GtkWidget *widget, GdkEventButton *event, gpointer user_data);
void on_game_restart_button_clicked(GtkWidget *button, gpointer user_data);
void on_save_button_clicked(GtkWidget *button, gpointer user_data);
void on_game_quit_button_clicked(GtkWidget *button, gpointer user_data);

#endif
