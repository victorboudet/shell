/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-kylian.labrador
** File description:
** clean_arg
*/

#include "shell.h"

void add_char(formats_t *f, char c, bool a)
{
    if (a) {
        int len = my_strlen(f->curr->curr);
        f->curr->curr = realloc(f->curr->curr, len + 2);
        f->curr->curr[len] = c;
        f->curr->curr[len + 1] = '\0';
    } else {
        f->curr->next = calloc(1, sizeof(arg_t));
        f->curr = f->curr->next;
        f->curr->curr = calloc(1, sizeof(char));
        f->curr->next = NULL;
    }
}

int guill(formats_t *f)
{
    if (*f->line == '\'' && !f->gd) {
        f->gs = !f->gs;
        return 1;
    }
    if (*f->line == '\"' && !f->gs) {
        f->gd = !f->gd;
        return 1;
    }
    if (f->gs || f->gd) {
        ADD_CHAR;
        return 1;
    }
    return 0;
}

// >    1
// >>   2
// <<   3
// <    4
// |    5
// ||   6
// &&   7
// ;    8
int separator(formats_t *f)
{
    if (!strncmp(f->line, ">>", 2) || !strncmp(f->line, "<<", 2) || !strncmp(
            f->line, "||", 2) || !strncmp(f->line, "&&", 2)) {
        if (my_strlen(f->curr->curr)) ADD_ARG;
        ADD_SEP(((!strncmp(f->line, "||", 2) || !strncmp(f->line, "&&", 2))
            ? MAIN_SEP : SUB_SEP));
        ADD_CHAR;
        f->line++;
        ADD_CHAR;
        ADD_ARG;
        return 1;
    }
    if (*f->line == '|' || *f->line == ';' || *f->line == '<' ||
        *f->line == '>') {
        if (my_strlen(f->curr->curr)) ADD_ARG;
        ADD_SEP((*f->line == ';') ? MAIN_SEP : SUB_SEP);
        ADD_CHAR;
        ADD_ARG;
        return 1;
    }
    return 0;
}

int space(formats_t *f)
{
    if ((*f->line == ' ' || *f->line == '\t')) {
        if (my_strlen(f->curr->curr) == 0) {
            return 1;
        }
        ADD_ARG;
        return 1;
    }
    return 0;
}

char **clean_arg(char *line)
{
    formats_t *f = calloc(1, sizeof(formats_t));
    f->line = line;
    f->gs = false;
    f->gd = false;
    f->first = calloc(1, sizeof(arg_t));
    f->curr = f->first;
    for (; *f->line != '\n'; f->line++) {
        if (guill(f)) {
            continue;
        }
        if (separator(f)) {
            continue;
        }
        if (space(f)) {
            continue;
        }
        ADD_CHAR;
    }
    return linked_list_to_array(f->first);
}
