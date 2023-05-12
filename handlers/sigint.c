/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell1-victor.boudet
** File description:
** sigint
*/

#include "shell.h"

void sigint_handler(int sig)
{
    (void) sig;
    pid_t a = process(0, false);
    if (a) {
        kill(process(0, 0), SIGINT);
        my_putchar('\n');
    } else {
        printf("\n");
        print_tty();
    }
}
