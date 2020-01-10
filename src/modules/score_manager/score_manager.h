#ifndef SCORES_MANAGER_H
#define SCORES_MANAGER_H

#include "imports.h"

typedef struct score_data
{
    int score;
    char username[101];
} score_data;

char *scores_file;
score_data scores[1000];
int scores_length;
int score;

void set_scores_file(char *file_path);
void load_scores();
void update_score();
void add_score(int score, const char *user);

#endif
