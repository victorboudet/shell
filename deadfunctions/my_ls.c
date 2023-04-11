/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell1-victor.boudet
** File description:
** my_ls
*/

#include "shell.h"

int my_ls(char **arg, char **env)
{
    int ret = 0;
    pid_t a = fork();
    if (a == 0) {
        execve("/bin/ls", arg, env);
    } else {
        process(a, 1);
        wait(&ret);
        process(0, 1);
    }
    return WEXITSTATUS(ret);
}
