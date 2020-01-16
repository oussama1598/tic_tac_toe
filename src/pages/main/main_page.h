#ifndef MAIN_PAGE_H
#define MAIN_PAGE_H

#include "imports.h"

/**
 * Points to the main page window.
*/
GtkWidget *main_page_window;
/**
 * Points to the new game button.
*/
GtkButton *new_game_button;
/**
 * Points to the load game button.
*/
GtkButton *load_game_button;
/**
 * Points to the score button.
*/
GtkButton *score_button;
/**
 * Points to the about button
*/
GtkButton *about_button;
/**
 * Points to the signout button.
*/
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
