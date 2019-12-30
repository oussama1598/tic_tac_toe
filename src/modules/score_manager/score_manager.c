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

    char *scores_file_content, **scores_data;
    int file_length = load_file(scores_file, &scores_file_content);

    if (file_length > 0)
    {

        int size = split(scores_file_content, "\n", &scores_data);

        scores = (score_data *)malloc(sizeof(score_data) * size);

        for (int i = 0; i < size; i++)
        {
            char **scoredata;
            score_data score_content;

            split(scores_data[i], ":", &scoredata);

            if (strstr(scoredata[1], logged_in_user) != NULL)
                score = atoi(scoredata[0]);

            strcpy(score_content.username, scoredata[1]);
            score_content.score = atoi(scoredata[0]);

            scores[i] = score_content;

            scores_length += 1;

            free(scoredata);
        }

        if (scores_length > 0)
            qsort(scores, scores_length, sizeof(score_data), compare_scores_reverse);

        free(scores_file_content);
    }
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
