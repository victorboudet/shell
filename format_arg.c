/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-kylian.labrador
** File description:
** format_arg
*/

#include "shell.h"

static int check_sep(char *str)
{
    if (*str == '|')
        return PIPE;
    if (*str == '>' && *(str + 1) == '>')
        return DOUBLE_EXIT_REDIR;
    if (*str == '<' && *(str + 1) == '<')
        return DOUBLE_INPUT_REDIR;
    if (*str == '>')
        return EXIT_REDIR;
    if (*str == '<')
        return INPUT_REDIR;
    return 0;
}

format_t *format(char **str)
{
    int k = 0, i = 0, j = 0, ind = 0;
    format_t *f = malloc(sizeof(format_t));
    f->tab = malloc(sizeof(int) * (array_len(str) + 1));
    f->dest = malloc(sizeof(char **) * (array_len(str) + 1));
    for (int j = 0; j <= array_len(str); j++)
        f->dest[j] = malloc_2d(array_len(str)*100, my_strlen(str[j])*100);
    f->dest[array_len(str)] = NULL;
    for (i = 0; str[i] != NULL; j++, i++) {
        if ((f->tab[ind] = check_sep(str[i]))) {
            f->dest[k][j] = NULL;
            k++;
            j = -1;
            ind++;
            continue;
        }
        my_strcpy(f->dest[k][j], str[i]);
    }
    f->dest[k][j] = NULL;
    f->dest[k + 1] = NULL;
    return f;
}
