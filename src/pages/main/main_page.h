#ifndef MAIN_PAGE_H
#define MAIN_PAGE_H

#include "imports.h"

GtkWidget *main_page_window;
GtkButton *new_game_button;
GtkButton *load_game_button;
GtkButton *score_button;
GtkButton *about_button;
GtkButton *signout_button;

void main_page_init();
void show_main_page();
void close_main_page();

// signals
void on_new_game_button_clicked(GtkButton *button, gpointer user_data);
void on_load_game_button_clicked(GtkButton *button, gpointer user_data);
void on_score_button_clicked(GtkButton *button, gpointer user_data);
void on_about_button_clicked(GtkButton *button, gpointer user_data);
void on_signout_button_clicked(GtkButton *button, gpointer user_data);

#endif
