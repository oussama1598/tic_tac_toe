#ifndef NEW_GAME_PAGE_H
#define NEW_GAME_PAGE_H

#include "imports.h"

#define AGAINST_AI 1
#define AGAINST_RADNOM 2

GtkWidget *new_game_page_window;
GtkButton *new_game_ai_button;
GtkButton *new_game_random_button;
GtkButton *new_game_back_button;

void new_game_page_init();
void show_new_game_page();
void close_new_game_page();

// signals
void on_new_game_choose_button_clicked(GtkButton *button, gpointer user_data);
void on_new_game_back_button_clicked(GtkButton *button, gpointer user_data);

#endif
