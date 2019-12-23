#ifndef SIGNIN_PAGE_H
#define SIGNIN_PAGE_H

#include "imports.h"

GtkWidget *signin_page_window;
GtkButton *signin_button;
GtkButton *signup_show_button;
GtkEntry *signin_username_input;
GtkEntry *signin_password_input;
GtkLabel *signin_error;

void signin_page_init();
void show_signin_page();
void close_signin_page();
void signin_hide_error();
void signin_show_error(char *str);
void signin_clear_entries();

// signals
int on_signin_button_clicked(GtkButton *button, gpointer user_data);
void on_signup_show_button_clicked(GtkButton *button, gpointer user_data);

#endif
