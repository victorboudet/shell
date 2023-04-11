/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell1-victor.boudet
** File description:
** my_unsetenv
*/

#include "shell.h"

int my_unsetenv(char **arg)
{
    if (arg[1] == NULL) {
        my_putstr("unsetenv: Too few arguments.\n");
        return 1;
    }
    for (int i = 1; arg[i] != NULL; i++)
        remove_env(arg[i]);
    return 0;
}
