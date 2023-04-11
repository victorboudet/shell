/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell1-victor.boudet
** File description:
** sigbase
*/

#include "shell.h"

pid_t process(pid_t pid, bool act)
{
    static pid_t pid_save = 0;
    if (act == true) {
        pid_save = pid;
        return 0;
    }
    return pid_save;
}

void set_signal(void)
{
    signal(SIGINT, sigint_handler);
    signal(SIGSEGV, segf_handler);
}
