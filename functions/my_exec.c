/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell1-victor.boudet
** File description:
** my_exec
*/

#include "shell.h"

char *get_varenv(char *name);
char *crop_b(char *str, int nb);

const error_t err[] = {
    {139, "Segmentation fault (core dumped)"},
    {136, "Floating exception (core dumped)"},
    {138, "Bus error (core dumped)"},
    {134, "Abort (core dumped)"},
    {132, "Illegal instruction (core dumped)"},
    {0, NULL}
};

void print_coredump(int ret)
{
    for (int i = 0; err[i].msg != NULL; i++) {
        if (ret == err[i].code) {
            my_putstr(err[i].msg);
            my_putchar('\n');
            return;
        }
    }
}

char *test(char *arg)
{
    (void) arg;
    char *path = get_varenv("PATH") + 5;
    char *tmp = strtok(path, ":");
    for (int i = 0; tmp != NULL; i++) {
        tmp = my_strcat(my_strcat(tmp, "/"), arg);
        if (access(tmp, F_OK) == 0) {
            return tmp;
        }
        tmp = strtok(NULL, ":");
    }
    return NULL;
}

int my_script(char **arg)
{
    int ret = 0;
    pid_t pid = 0;
    pid = fork();
    if (pid == 0) {
        if (arg[0] == NULL) { my_putstr("Invalid null command.\n"); return 1;
        }
        execve(arg[0], arg, NULL); my_putstr(arg[0]);
        if (errno == 13) my_putstr(": Permission denied.\n");
        if (errno == 8)
            my_putstr(": Exec format error. Wrong Architecture.\n");
        if (errno != 8 && errno != 13) my_putstr(": Command not found.\n");
        exit(1);
    } else { wait(&ret);
        if (WIFSIGNALED(ret)) my_putstr(strsignal(WTERMSIG(ret)));
        if (WCOREDUMP(ret)) my_putstr(" (core dumped)");
        if (WIFEXITED(ret)) ret = WEXITSTATUS(ret);
        else
        my_putchar('\n');
    }
    return ret;
}

int my_exec(char **arg)
{
    int ret = 0;
    pid_t a = fork();
    char *path = NULL;
    (void) path;
    if (a == 0) {
        if (!my_strncomp(arg[0], "./", 2))
            execve(test(arg[0]) , arg, get_env());
        ret = my_script(arg);
        exit(ret);
    } else {
        process(a, 1);
        wait(&ret);
        process(0, 1);
    }
    return WEXITSTATUS(ret);
}
