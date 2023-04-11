/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell1-victor.boudet
** File description:
** get_arg
*/

#include "shell.h"
char *my_revstr(char *str);

bool guillemets(char c, char tr)
{
    static bool dg = false, sg = false;
    if (tr) {
        if (tr == '\"' && dg)
            return true;
        if (sg && tr == '\'')
            return true;
        return false;
    }
    if (c == '\"' && !sg) {
        dg = dg ? false : true;
        return dg;
    }
    if (c == '\'' && !dg) {
        sg = sg ? false : true;
        return sg;
    }
    if (dg || sg)
        return true;
    return false;
}

bool guil(parse_t *p)
{
    if (guillemets(*p->str, 0)) {
        if (p->in == false) {
            p->in = true;
            p->j ? p->dest[p->i][p->j] = '\0' : 0;
            p->j ? p->i++ : 0;
            p->j ? p->j = 0 : 0;
            return true;
        }
        p->dest[p->i][p->j++] = *p->str;
        return true;
    }
    if (p->in == true) {
        if (p->j)
            p->i++;
        p->in = false;
        return true;
    }
    return false;
}

parse_t *init_p(char *str, char **dest)
{
    parse_t *p = malloc(sizeof(parse_t));
    *p = (parse_t) {0, 0, false, dest, str};
    return p;
}

bool single_arg(parse_t *p, bool a)
{
    p->dest[p->i][p->j] = '\0';
    if (p->j)
        p->i++;
    p->dest[p->i][0] = *p->str;
    if (a) {
        p->str++;
        p->dest[p->i][1] = *p->str;
        p->dest[p->i][2] = '\0';
    } else {
        p->dest[p->i][1] = '\0';
    }
    p->i++;
    p->j = 0;
    return true;
}

bool check(parse_t *p)
{
    if ((*p->str == '>' && p->str[1] == '>') ||
        (*p->str == '<' && p->str[1] == '<')) {
        return single_arg(p, true);
    }

    if (*p->str == '|' || *p->str == '>' || *p->str == '<') {
        return single_arg(p, false);
    }
    return false;
}
