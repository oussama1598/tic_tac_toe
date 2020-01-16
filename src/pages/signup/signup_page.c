#include "signup_page.h"

/**
 * Inits the signup page.
*/
void signup_page_init()
{
    signup_page_window = GTK_WIDGET(gtk_builder_get_object(builder, "signup_page"));

    // init widgets
    signup_button = GTK_BUTTON(gtk_builder_get_object(builder, "signup_button"));
    signin_show_button = GTK_BUTTON(gtk_builder_get_object(builder, "signin_show_button"));
    signup_username_input = GTK_ENTRY(gtk_builder_get_object(builder, "signup_username_input"));
    signup_password_input = GTK_ENTRY(gtk_builder_get_object(builder, "signup_password_input"));
    signup_error = GTK_LABEL(gtk_builder_get_object(builder, "signup_error"));

    // hide the error widget
    signup_hide_error();

    // init signals
    g_signal_connect(signup_page_window, "destroy", G_CALLBACK(on_destroy), NULL);
    g_signal_connect(signup_button, "clicked", G_CALLBACK(on_signup_button_clicked), NULL);
    g_signal_connect(signin_show_button, "clicked", G_CALLBACK(on_signin_show_button_clicked), NULL);
}

/**
 * Shows the signup page.
*/
void show_signup_page()
{
    gtk_widget_show(signup_page_window);
}

/**
 * Closes the signup page.
*/
void close_signup_page()
{
    gtk_widget_hide(signup_page_window);
}

/**
 * Hides the error label.
*/
void signup_hide_error()
{
    gtk_widget_hide(GTK_WIDGET(signup_error));
}

/**
 * Shows the error label.
 * 
 * @param str a message to be set as an error.
*/
void signup_show_error(char *str)
{
    gtk_widget_show(GTK_WIDGET(signup_error));
    gtk_label_set_text(signup_error, str);
}

/**
 * A callback function that gets called when the signup button is pressed.
*/
int on_signup_button_clicked(GtkButton *button, gpointer user_data)
{
    const char *username = gtk_entry_get_text(signup_username_input);
    const char *password = gtk_entry_get_text(signup_password_input);

    if (strlen(username) < 3 || strlen(username) > 15)
    {
        signup_show_error("Username can't be less than 3 or greater than 15.");

        return 0;
    }

    if ((strlen(password) < 3 || strlen(password) > 15))
    {
        signup_show_error("Password can't be less than 3 or greater than 15.");

        return 0;
    }

    if (check_if_user_exists(username))
    {
        signup_show_error("This username exists.");

        return 0;
    }

    add_user(username, password); // add user to the database
    add_score(0, username);       // add the score of 0 to that user

    signup_show_error("You've registred successfly.");

    return 0;
}

/**
 * A callback function that gets called when the show signin button is pressed.
*/
void on_signin_show_button_clicked(GtkButton *button, gpointer user_data)
{
    close_signup_page();
    show_signin_page();
}
