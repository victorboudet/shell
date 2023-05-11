/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-kylian.labrador
** File description:
** pipeu
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "shell.h"

// >    1
// >>   2
// <    3
// <<   4
// |    5
// ||   6
// &&   7
// ;    8
static void action(int nb, char **commands[], int i)
{
    return;
    int out_fd;
    switch (nb) {
        case 2:
            out_fd = open(commands[i + 1][0], O_WRONLY | O_CREAT | O_APPEND,
                0644);
            dup2(out_fd, STDOUT_FILENO);
            close(out_fd);
            break;
        case 4:
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
        if (pid == 0) { dup2(in_fd, STDIN_FILENO);
            close(in_fd);
            dup2(fd[1], STDOUT_FILENO);
            close(fd[0]);
            close(fd[1]);
            action(tab[i], commands, i);
            exit(last_exec(commands[i]));
        }
        close(in_fd);
        close(fd[1]);
        in_fd = fd[0];
    }
    dup2(in_fd, STDIN_FILENO);
    close(in_fd);
    exit(last_exec(commands[num_commands - 1]));
}
