#ifndef SIGNUP_PAGE_H
#define SIGNUP_PAGE_H

#include "imports.h"

GtkWidget *signup_page_window;
GtkButton *signup_button;
GtkButton *signin_show_button;
GtkEntry *signup_username_input;
GtkEntry *signup_password_input;
GtkLabel *signup_error;

void signup_page_init();
void show_signup_page();
void close_signup_page();
void signup_hide_error();
void signup_show_error(char *str);

// signals
int on_signup_button_clicked(GtkButton *button, gpointer user_data);
void on_signin_show_button_clicked(GtkButton *button, gpointer user_data);

#endif
