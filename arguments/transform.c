/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-kylian.labrador
** File description:
** transform
*/

#include "shell.h"

const tabe_t pat[] = {
    {">", 1},
    {">>", 2},
    {"<", 3},
    {"<<", 4},
    {"|", 5},
    {"||", 6},
    {"&&", 7},
    {";", 8},
    {NULL, 0}
};

int get_ind(char *str)
{
    for (int i = 0; pat[i].name != NULL; i++) {
        if (strcmp(pat[i].name, (str + 1)) == 0)
            return pat[i].value;
    }
    return 0;
}

form_t *transform(char **input)
{
    form_t *t = calloc(1, sizeof(form_t));
    for (int i = 0; input[i] != NULL; i++) if (input[i][0] == SUB_SEP) t->ns++;
    t->sep = calloc(t->ns + 1, sizeof(int));
    int nWords = 0, wordIndex = 0, sepIndex = 0;
    for (nWords = 0; input[nWords] != NULL; nWords++);
    t->cmd = calloc((t->ns + 2), sizeof(char **));
    t->cmd[sepIndex] = calloc((nWords + 1), sizeof(char *));
    t->cmd[sepIndex][wordIndex] = NULL;
    for (int i = 0; input[i] != NULL; i++) {
        if (input[i][0] == SUB_SEP) { t->sep[sepIndex++] = get_ind(input[i]);
            t->cmd[sepIndex] = calloc((nWords + 1), sizeof(char *));
            t->cmd[sepIndex][0] = NULL;
            wordIndex = 0;
        } else { t->cmd[sepIndex][wordIndex] = strdup(input[i]);
            t->cmd[sepIndex][++wordIndex] = NULL;
        }
    }
    t->cmd[t->ns + 1] = NULL;
    return t;
}
