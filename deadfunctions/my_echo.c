/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell1-victor.boudet
** File description:
** my_echo
*/

#include "shell.h"

int my_echo(char **arg, char **env)
{
    for (int i = 1; arg[i] != NULL; i++) {
            my_putstr(arg[i]);
            my_putchar(' ');
    }
    my_putchar('\n');
    return 0;
    (void) env;
}
