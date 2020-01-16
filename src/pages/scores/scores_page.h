#ifndef SCORES_PAGE_H
#define SCORES_PAGE_H

#include "imports.h"

/**
 * Points to the scores page window.
*/
GtkWidget *scores_page_window;
/**
 * Points to the scores back button.
*/
GtkButton *scores_back_button;
/**
 * Points to the all the 10 labels.
*/
GtkLabel *score_user_info_labels[10];

void scores_page_init();
void show_scores_page();
void close_scores_page();
void clear_all_labels();
void render_scores();

void on_scores_back_button_clicked(GtkButton *button, gpointer user_data);

#endif
