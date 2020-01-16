#ifndef GAME_H
#define GAME_H

#include "imports.h"

#define PLAYER_WON 1
#define AI_WON 2
#define NO_MOVES_LEFT -1
#define O_SIGN 1
#define X_SIGN 2
#define AGAINST_AI 1
#define AGAINST_RADNOM 2

/**
 * Points to the game page window.
*/
GtkWidget *game_page_window;
/**
 * Points to the game save dialog.
*/
GtkWidget *game_save_dialog;
/**
 * Points to the game canvas.
*/
GtkWidget *game_canvas;
/**
 * Points to the game restart button.
*/
GtkMenuItem *game_restart_button;
/**
 * Points to the game quit button.
*/
GtkMenuItem *game_quit_button;
/**
 * Points to the game save button.
*/
GtkMenuItem *game_save_button;
/**
 * Points to the game history button.
*/
GtkMenuItem *game_history_button;
/**
 * Points to the game message label.
*/
GtkLabel *game_message_box;

/**
 * The error's dialog flag.
*/
GtkDialogFlags flags;

/**
 * The board's matrix.
*/
unsigned int game_matrix[3][3];
/**
 * The board's matrix history.
*/
unsigned int game_history[3][3];
/**
 * The canvas's width.
*/
int canvas_width;
/**
 * The canvas's height.
*/
int canvas_height;

/**
 * The game's state.
 * 1 means it's finished.
*/
int game_finished;
/**
 * The player's sign.
*/
int player_sign;
/**
 * The ai's type. 
*/
int against_ai_type;
/**
 * Render the win line for a particular line. 
*/
int game_line_win;
/**
 * Render the win line for a particular column. 
*/
int game_column_win;
/**
 * Number of turns played. 
*/
int turns_played;

void game_page_init();
void show_game_page(int ai_type, int did_back);
void close_game_page();
void init_game();
void clear_game();
void load_game_save(char *ai_type, char *saved_player_sign, char *board_state);
void save_game();
void set_message(const char *str);
int is_board_full();
void game_check_if_win();
void redraw_game_canvas();

// signals
void on_draw(GtkWidget *canvas, cairo_t *cr, gpointer user_data);
void on_game_canvas_mouse_pressed(GtkWidget *widget, GdkEventButton *event, gpointer user_data);
void on_game_restart_button_clicked(GtkMenuItem *button, gpointer user_data);
void on_save_button_clicked(GtkMenuItem *button, gpointer user_data);
void on_game_quit_button_clicked(GtkMenuItem *button, gpointer user_data);
void on_game_history_button_clicked(GtkMenuItem *button, gpointer user_data);

#endif
