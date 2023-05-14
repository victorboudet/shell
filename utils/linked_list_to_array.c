/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-kylian.labrador
** File description:
** linked_list_to_array
*/

#include "shell.h"

char **linked_list_to_array(arg_t *first)
{
    int len = 0;
    arg_t *tmp = first;
    for (; tmp != NULL; tmp = tmp->next) {
        len++;
    }
    char **ret = calloc(len + 1, sizeof(char *));
    tmp = first;
    for (int i = 0; tmp != NULL; tmp = tmp->next, i++) {
        ret[i] = tmp->curr;
    }
    return ret;
}

void sep(char *str, char *stre)
{
    my_putstr(str);
    my_putstr(": ");
    my_putstr(stre);
    my_putchar('\n');
}
