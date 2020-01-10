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
GtkMenuItem *game_restart_button;
GtkMenuItem *game_quit_button;
GtkMenuItem *game_save_button;
GtkMenuItem *game_history_button;
GtkLabel *game_message_box;

GtkDialogFlags flags;

unsigned int game_matrix[3][3];
unsigned int game_history[3][3];
int canvas_width;
int canvas_height;

int game_finished;
int player_sign;
int against_ai_type;
int game_line_win;
int game_column_win;
int turns_played;

void game_page_init();
void show_game_page(int ai_type, int did_back);
void close_game_page();
void init_game();
void clear_game();
void load_game_save(char *ai_type, char *board_state);
void save_game();
gint show_error_saving_dialog();
void set_message(const char *str);
void game_check_if_win(int isTie);
void redraw_game_canvas();

// signals
void on_draw(GtkWidget *canvas, cairo_t *cr, gpointer user_data);
void on_game_canvas_mouse_pressed(GtkWidget *widget, GdkEventButton *event, gpointer user_data);
void on_game_restart_button_clicked(GtkMenuItem *button, gpointer user_data);
void on_save_button_clicked(GtkMenuItem *button, gpointer user_data);
void on_game_quit_button_clicked(GtkMenuItem *button, gpointer user_data);
void on_game_history_button_clicked(GtkMenuItem *button, gpointer user_data);

#endif
