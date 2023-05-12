/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-kylian.labrador
** File description:
** print_tty
*/

#include "shell.h"

void print_tty(void)
{
    char cwd[1024];

    getcwd(cwd, sizeof(cwd));
    printf("%s@%s:~%s$>", getenv("USER"), getenv("USER"), cwd);
    fflush(stdout);
}
