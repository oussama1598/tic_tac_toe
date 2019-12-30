#ifndef SCORES_PAGE_H
#define SCORES_PAGE_H

#include "imports.h"

GtkWidget *scores_page_window;
GtkButton *scores_back_button;
GtkLabel *score_user_info_labels[10];

void scores_page_init();
void show_scores_page();
void close_scores_page();
void clear_all_labels();
void render_scores();

void on_scores_back_button_clicked(GtkButton *button, gpointer user_data);

#endif
