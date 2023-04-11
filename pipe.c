/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell2-victor.boudet
** File description:
** pipe
*/

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

void double_close(int fd1, int fd2);
format_t *format(char **str);
char **get_arg(char *str, int a);

void action(int nb, char **commands[], int i)
{
    int out_fd;
    switch (nb) {
        case EXIT_REDIR:
            out_fd = open(commands[i + 1][0], O_WRONLY | O_CREAT | O_APPEND,
                0644);
            dup2(out_fd, STDOUT_FILENO);
            close(out_fd);
            break;
        case DOUBLE_EXIT_REDIR:
            out_fd = open(commands[i + 1][0], O_WRONLY | O_CREAT | O_TRUNC,
                0644);
            dup2(out_fd, STDOUT_FILENO);
            close(out_fd);
            break;
    }
}

void generic_pipe(char **commands[], int num_commands, int *tab)
{
    int fd[2], in_fd = dup(STDIN_FILENO);
    pid_t pid;
    for (int i = 0; i < num_commands - 1; i++) {
        pipe(fd);
        pid = fork();
        if (pid == 0) {
            dup2(in_fd, STDIN_FILENO);
            close(in_fd);
            dup2(fd[1], STDOUT_FILENO);
            double_close(fd[0], fd[1]);
            action(tab[i], commands, i);
            exit(last_exec(commands[i]));
        }
        double_close(in_fd, fd[1]);
        in_fd = fd[0];
    }
    dup2(in_fd, STDIN_FILENO);
    close(in_fd);
    exit(last_exec(commands[num_commands - 1]));
}

int double_array_len(char ***array)
{
    int i = 0;
    for (i = 0; array[i] != NULL; i++);
    return i;
}

static int exec_command(char *line, int ret)
{
    char **arg = get_arg(line, ret);
    int reto = 0;
    if (arg[0] == NULL) {
        return 0;
    }
    format_t *f = format(arg);
    if (f->dest[1] == NULL) {
        return last_exec(arg);
    }
    pid_t pid = fork();
    if (pid == 0) {
        generic_pipe(f->dest, double_array_len(f->dest), f->tab);
    } else {
        wait(&reto);
    }
    return WEXITSTATUS(reto);
}

int check_line(char *line, int ret)
{
    line = strtok(line, ";");
    while (line != NULL && line[0] != 10) {
        ret = exec_command(line, ret);
        line = strtok(NULL, ";");
    }
    return ret;
}
