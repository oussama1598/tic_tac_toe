#ifndef LOAD_GAME_PAGE_H
#define LOAD_GAME_PAGE_H

#include "imports.h"

/**
 * Points to the load game window.
*/
GtkWidget *load_game_page_window;
/**
 * Points to the load game back button.
*/
GtkButton *load_game_back_button;
/**
 * Points to the load game select button.
*/
GtkButton *load_game_select_button;
/**
 * Points to the first save option.
*/
GtkRadioButton *load_game_option1;
/**
 * Points to the second save option.
*/
GtkRadioButton *load_game_option2;
/**
 * Points to the third save option.
*/
GtkRadioButton *load_game_option3;
/**
 * Points to the first save option label.
*/
GtkLabel *load_game_option1_label;
/**
 * Points to the second save option label.
*/
GtkLabel *load_game_option2_label;
/**
 * Points to the third save option label.
*/
GtkLabel *load_game_option3_label;

void load_game_page_init();
void show_load_game_page();
void close_load_game_page();
void clear_and_disable_all_options();
void render_radio_button(int id, char *text_to_render);
void render_saves_selection();
void enable_disable_load_button();

void on_load_game_back_button_clicked(GtkButton *button, gpointer user_data);
void on_load_game_select_button_clicked(GtkButton *button, gpointer user_data);

#endif
