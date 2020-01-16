#include "signin_page.h"

/**
 * Inits the signin page.
*/
void signin_page_init()
{
    signin_page_window = GTK_WIDGET(gtk_builder_get_object(builder, "signin_page"));

    // init widgets
    signin_button = GTK_BUTTON(gtk_builder_get_object(builder, "signin_button"));
    signup_show_button = GTK_BUTTON(gtk_builder_get_object(builder, "signup_show_button"));
    signin_username_input = GTK_ENTRY(gtk_builder_get_object(builder, "signin_username_input"));
    signin_password_input = GTK_ENTRY(gtk_builder_get_object(builder, "signin_password_input"));
    signin_error = GTK_LABEL(gtk_builder_get_object(builder, "signin_error"));

    // hide the error widget
    signin_hide_error();

    // init signals
    g_signal_connect(signin_page_window, "destroy", G_CALLBACK(on_destroy), NULL);
    g_signal_connect(signin_button, "clicked", G_CALLBACK(on_signin_button_clicked), NULL);
    g_signal_connect(signup_show_button, "clicked", G_CALLBACK(on_signup_show_button_clicked), NULL);
}

/**
 * Shows the about page.
*/
void show_signin_page()
{
    gtk_widget_show(signin_page_window);
}

/**
 * Closes the about page.
*/
void close_signin_page()
{
    gtk_widget_hide(signin_page_window);
}

/**
 * Hides the error label.
*/
void signin_hide_error()
{
    gtk_widget_hide(GTK_WIDGET(signin_error));
}

/**
 * Shows the error label.
 * 
 * @param str a message to be set as an error.
*/
void signin_show_error(char *str)
{
    gtk_widget_show(GTK_WIDGET(signin_error));
    gtk_label_set_text(signin_error, str);
}

/**
 * Clears all the entries.
*/
void signin_clear_entries()
{
    gtk_entry_set_text(signin_username_input, "");
    gtk_entry_set_text(signin_password_input, "");
}

/**
 * A callback function that gets called when the signin button is pressed.
*/
int on_signin_button_clicked(GtkButton *button, gpointer user_data)
{
    const char *username = gtk_entry_get_text(signin_username_input);
    const char *password = gtk_entry_get_text(signin_password_input);

    if (strlen(username) < 3 || strlen(username) > 15)
    {
        signin_show_error("Username can't be less than 3 or greater than 15.");

        return 0;
    }

    if ((strlen(password) < 3 || strlen(password) > 15))
    {
        signin_show_error("Password can't be less than 3 or greater than 15.");

        return 0;
    }

    if (!check_if_user_exists(username))
    {
        signin_show_error("Username does not exist.");

        return 0;
    }

    if (!authenticate_user(username, password))
    {
        signin_show_error("Authentication failed.");

        return 0;
    }

    signin_hide_error();

    // set logged in user
    strcpy(logged_in_user, username);

    // load the saves for this user
    load_saves();

    // load the score of that user
    load_scores();

    // close this page and open up the game page
    signin_clear_entries();
    close_signin_page();
    show_main_page();

    return 0;
}

/**
 * A callback function that gets called when the show signup button is pressed.
*/
void on_signup_show_button_clicked(GtkButton *button, gpointer user_data)
{
    close_signin_page();
    show_signup_page();
}
