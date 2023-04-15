/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell2-victor.boudet
** File description:
** new_arg
*/

#include "shell.h"

char *my_revstr(char *str);
char **loop(char *str, char**dest);
#include <stdlib.h>
char **malloc_2d(int x, int y);

char **my_str_to_word_array(char *str)
{
    int len = my_strlen(str) + 1;
    char **dest = malloc_2d_char(len, len);
    return loop(str, dest);
}

char *my_int_to_str(int nb)
{
    int len = 0;
    char *dest = NULL;

    if (nb == 0) return "0";
    for (int i = nb; i > 0; i /= 10) len++;
    dest = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++) {
        dest[i] = (nb % 10) + 48;
        nb /= 10;
    }
    dest[len] = '\0';
    return my_revstr(dest);
}

char **get_arg(char *str, int a)
{
    char **dest = my_str_to_word_array(str);
    for (int i = 0; dest[i] != NULL; i++) {
        if (my_str_comp("$?", dest[i])) {
            dest[i] = my_int_to_str(a);
        }
    }
    return dest;
}
