#include "imports.h"

/*! \mainpage Tic_Tac_Toe Docs
*/

/**
 * This function gets called at the first run of this program.
 *
 * @param argc Number of arguments given to this program.
 * @param argv a list of characters representing the arguments given to this program
 * @return 0 to safely exit the program when its done without any errors
 */
int main(int argc, char **argv)
{
    gtk_init(&argc, &argv);

    // load the users
    set_users_file("users.txt");
    load_users();

    // set the saves file
    set_saves_file("saves.txt");

    // set the scores file
    set_scores_file("scores.txt");

    // add individual templates
    config_templates(9, "css/style.css");
    add_template((template){"pages/signin/signin.glade", signin_page_init});
    add_template((template){"pages/signup/signup.glade", signup_page_init});
    add_template((template){"pages/main/main.glade", main_page_init});
    add_template((template){"pages/new_game/new_game.glade", new_game_page_init});
    add_template((template){"pages/load_game/load_game.glade", load_game_page_init});
    add_template((template){"pages/about/about.glade", about_page_init});
    add_template((template){"pages/scores/scores.glade", scores_page_init});
    add_template((template){"pages/game/game.glade", game_page_init});
    add_template((template){"pages/history/history.glade", history_page_init});

    // load all the templates and initialize them
    app_init();

    // show the login page
    show_signin_page();

    g_object_unref(builder); // frees the pointer builder
    gtk_main();              // enter the main loop

    return 0;
}
