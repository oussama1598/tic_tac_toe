#ifndef SCORES_MANAGER_H
#define SCORES_MANAGER_H

#include "imports.h"

/**
 * A structure that will contain the score's data.
*/
typedef struct score_data
{
    /**
     * The score for the a specific user.
    */
    int score;
    /**
     * A username for a specific user.
    */
    char username[101];
} score_data;

/**
 * The scores's file path.
*/
char *scores_file;
/**
 * The scores list of type {@link score_data} it can hold up to 1000 scores.
*/
score_data scores[1000];
/**
 * The scores list length.
*/
int scores_length;
/**
 * The current signed in user's score.
*/
int score;

void set_scores_file(char *file_path);
void load_scores();
void update_score();
void add_score(int score, const char *user);

#endif
