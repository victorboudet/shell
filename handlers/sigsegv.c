/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell1-victor.boudet
** File description:
** segf_handler
*/

#include "shell.h"

void segf_handler(int sig)
{
    (void) sig;
    my_putstr("Segmentation fault");
    exit(84);
}
