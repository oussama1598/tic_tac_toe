#ifndef LOAD_GAME_PAGE_H
#define LOAD_GAME_PAGE_H

#include "imports.h"

GtkWidget *load_game_page_window;
GtkButton *load_game_back_button;
GtkButton *load_game_select_button;
GtkRadioButton *load_game_option1;
GtkRadioButton *load_game_option2;
GtkRadioButton *load_game_option3;
GtkLabel *load_game_option1_label;
GtkLabel *load_game_option2_label;
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
