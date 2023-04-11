/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell1-victor.boudet
** File description:
** my_clear
*/

#include "shell.h"

int my_clear(char **arg, char **env)
{
    (void) arg;
    my_putstr("\033[2J\033[1;1H");
    return 0;
    (void) env;
}
