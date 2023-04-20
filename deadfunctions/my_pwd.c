/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell1-victor.boudet
** File description:
** my_pwd
*/

#include "shell.h"

int my_pwd(char **arg, char **env)
{
    (void) arg;
    (void) env;
    char *buff = NULL;
    size_t bl = 0;

    my_putstr(getcwd(buff, bl));
    my_putchar('\n');
    return 0;
}
