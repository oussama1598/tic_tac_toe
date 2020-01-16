#ifndef SIGNUP_PAGE_H
#define SIGNUP_PAGE_H

#include "imports.h"
/**
 * Points to the signup page window.
*/
GtkWidget *signup_page_window;
/**
 * Points to the signup button.
*/
GtkButton *signup_button;
/**
 * Points to the show singin button.
*/
GtkButton *signin_show_button;
/**
 * Points to the username's entry.
*/
GtkEntry *signup_username_input;
/**
 * Points to the password's entry.
*/
GtkEntry *signup_password_input;
/**
 * Points to the error label.
*/
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
