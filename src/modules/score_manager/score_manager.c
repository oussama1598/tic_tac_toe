#include "score_manager.h"

void set_scores_file(char *file_path)
{
    scores_file = join_strings("./data/", file_path);
}

void load_scores()
{
    create_dir("./data");

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

        if (strcmp(score_content.username, logged_in_user) == 0) // this score belongs to the logged in user
            score = score_content.score;

        scores[scores_length] = score_content;
        scores_length += 1;
    }

    if (scores_length > 0)
        qsort(scores, scores_length, sizeof(score_data), compare_scores_reverse);

    fclose(scores_file_pointer);
}

void update_score()
{
    char data_to_save[2000];
    sprintf(data_to_save, "%d:%s:\n", score, logged_in_user);

    update_first_instance_in_file_of_user(scores_file, data_to_save, logged_in_user);

    for (int i = 0; i < scores_length; i++)
        if (strcmp(scores[i].username, logged_in_user) == 0)
        {
            scores[i].score = score;
        }

    if (scores_length > 0)
        qsort(scores, scores_length, sizeof(score_data), compare_scores_reverse);
}

void add_score(int score, const char *user)
{
    char data_to_save[2000];
    sprintf(data_to_save, "%d:%s:\n", score, user);

    append_to_file(scores_file, data_to_save);
}
