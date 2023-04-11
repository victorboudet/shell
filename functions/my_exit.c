/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell1-victor.boudet
** File description:
** my_exit
*/

#include "shell.h"

int my_exit(char **str)
{
    my_putstr("exit\n");
    exit(0);
    return 0;
    (void) str;
}
