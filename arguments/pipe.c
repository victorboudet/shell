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
int get_ind(char *str);

static int set_var(char *str, bool tr)
{
    static int act = 0;
    if (tr == true) {
        act = get_ind(str);
        return 0;
    }
    return act;
}

static char **strtoktok(char **array)
{
    static char **save = NULL;
    if (array != NULL && save == NULL) {
        save = array;
        return NULL;
    }
    if (save == NULL)
        return NULL;
    int i = 0;
    for (i = 0; save[i] != NULL && save[i][0] != MAIN_SEP; i++);
    char **ret = calloc(i + 1, sizeof(char *));
    if (ret == NULL) {
        return NULL;
    }
    for (i = 0; save[i] != NULL && save[i][0] != MAIN_SEP; i++)
        ret[i] = save[i];
    if (save[i] != NULL) set_var(save[i], true);
    ret[i] = NULL;
    save += i + 1;
    if (save[-1] == NULL) save = NULL;
    return ret;
}

static bool act(int ret)
{
    int a = set_var(NULL, false);
    if (a == 0) {
        return true;
    }
    if (a == 6 && ret == 0) {
        return true;
    }
    if (a == 7 && ret != 0) {
        return true;
    }
    return false;
}

static int exec_command(char **arg, int ret)
{
    int reto = 0;
    if (arg[0] == NULL)
        return 0;
    strtoktok(arg);
    char **tmp = NULL;
    for (int i = 0;(tmp = strtoktok(NULL)) != NULL; i++) {
        if (act(ret) && i) break;
        form_t *f = transform(tmp);
        if (f->cmd[1] == NULL) {
            (tmp[0][0] != '\0') ? ret = last_exec(tmp) : 1;
            continue;
        }
        pid_t pid = fork();
        if (pid == 0) {
            generic_pipe(f->cmd, f->ns + 1, f->sep);
        } else {
            wait(&reto);
        }
    }
    return WEXITSTATUS(reto);
}

int check_line(char *line, int ret)
{
    line = star(line);
    line = clean_str(line);
    line = strcat(line, "\n");
    char **arg = clean_arg(line);
    ret = exec_command(arg, ret);
    return ret;
}
