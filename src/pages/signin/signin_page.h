#ifndef SIGNIN_PAGE_H
#define SIGNIN_PAGE_H

#include "imports.h"

/**
 * Points to the signin page window.
*/
GtkWidget *signin_page_window;
/**
 * Points to the signin button.
*/
GtkButton *signin_button;
/**
 * Points to the show signup button.
*/
GtkButton *signup_show_button;
/**
 * Points to the username's entry.
*/
GtkEntry *signin_username_input;
/**
 * Points to the password's entry.
*/
GtkEntry *signin_password_input;
/**
 * Points to the error label.
*/
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
