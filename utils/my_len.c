/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell1-victor.boudet
** File description:
** my_strlen
*/

#include <stddef.h>
#include "shell.h"
bool guil(parse_t *p);
bool check(parse_t *p);
parse_t *init_p(char *str, char **dest);

char **loop(char *str, char **dest)
{
    parse_t *p = init_p(str, dest);
    for (; *p->str; p->str++) {
        if (check(p)) continue;
        if (guil(p)) continue;
        if (*p->str == 32 || *p->str == '\t') continue;
        if (*p->str == '\n') break;
        p->dest[p->i][p->j++] = *p->str;
        if (p->str[1] == ' ' || p->str[1] == '\t') {
            p->dest[p->i][p->j] = '\0';
            p->i++;
            p->j = 0;
        }
    }
    p->dest[p->i][p->j] = '\0';
    if (p->dest[p->i][0] == '\0')
        p->dest[p->i] = NULL;
    p->dest[p->i + 1] = NULL;
    return p->dest;
}

void double_close(int fd1, int fd2)
{
    close(fd1);
    close(fd2);
}
