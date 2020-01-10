#include "score_manager.h"

void set_scores_file(char *file_path)
{
    scores_file = join_strings("./data/", file_path);
}

void load_scores()
{
    mkdir("./data", 0700);

    if (!file_exists(scores_file))
    {
        append_to_file(scores_file, "");
    }

    scores_length = 0;

    FILE *scores_file_pointer = fopen(scores_file, "r");

    char score_line[250];

    while (fscanf(scores_file_pointer, "%s\n", score_line) != -1)
    {
        score_data score_content;

        score_content.score = atoi(strtok(score_line, ":"));
        strcpy(score_content.username, strtok(NULL, ":"));

        if (strstr(score_line, logged_in_user) != NULL) // this score belongs to the logged in user
        {
            score = score_content.score;
        }

        scores[scores_length] = score_content;
        scores_length += 1;
    }

    if (scores_length > 0)
        qsort(scores, scores_length, sizeof(score_data), compare_scores_reverse);

    fclose(scores_file_pointer);
}

void update_score()
{
}

void add_score(int score, const char *user)
{
    char data_to_save[2000];
    sprintf(data_to_save, "%d:%s:\n", score, user);

    append_to_file(scores_file, data_to_save);
}
