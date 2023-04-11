/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell1-victor.boudet
** File description:
** my_cat
*/

#include "shell.h"

int my_cat(char **arg, char **env)
{
    int ret = 0;
    pid_t a = fork();
    char *path = NULL;
    if (a == 0) {
        path = my_strcat("/bin/", arg[0]);
        execve(path, arg, env);
    } else {
        process(a, 1);
        wait(&ret);
        process(0, 1);
    }
    return WEXITSTATUS(ret);
}
