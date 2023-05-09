/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** clean_str
*/

#include "my.h"

char *clean_str(char *str)
{
    int x = 0;
    int y = 0;
    char *clean = malloc(sizeof(char) * strlen(str) + 1);
    while (str[x] == ' ' || str[x] == '\t')
        x++;
    for (; str[x] != 0 && str[x] != '\n'; x++, y++) {
        if (str[x] == '\t')
            str[x] = ' ';
        if (str[x] == ' ' && str[x + 1] == ' ')
            x++;
        clean[y] = str[x];
    }
    if (str[x - 1] == ' ')
        clean[y - 1] = 0;
    else
        clean[y] = 0;
    return clean;
}
