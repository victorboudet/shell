/*
** EPITECH PROJECT, 2023
** ter
** File description:
** main
*/

#include "my.h"

int tab_len(char **tab)
{
    int i = 0;
    for (; tab[i] != NULL; i++);
    return i;
}

char *supr(char *src, char del)
{
    int nb = 0;
    for (int i = 0; src[i] != 0; i++)
        if (src[i] == del)
            nb++;
    char *dest = malloc(sizeof(char) * (my_strlen(src) - nb + 1));
    for (int i = 0, j = 0; src[i] != 0; i++, j++) {
        if (src[i] == del) {
            i++;
        }
        dest[j] = src[i];
    }
    dest[strlen(src) - nb] = 0;
    return dest;
}

t_list *loop_bis(t_list *list)
{
    if (str_to_word_array(list->path, "*")[0] != NULL) {
        list->path = supr(str_to_word_array(list->path, "/")
        [tab_len(str_to_word_array(list->path, "/")) - 1], '*');
    }
    list->path = supr(list->path, '\0');
    if (list->name != NULL &&
    (strstr(list->name, list->path) != NULL || list->path[0] == '*')) {
        list->y++;
        list->new = realloc(list->new, sizeof(char *) * (list->y + 1));
        if (list->name_dir[1] != '/')
            list->new[list->y] = strdup(list->ent->d_name);
        else {
            list->new[list->y] = strdup(list->name_dir);
            list->new[list->y] = strcat(list->new[list->y], list->ent->d_name);
        }
    }
    return list;
}

t_list *init(char *av)
{
    t_list *list = malloc(sizeof(t_list));
    list->commande = str_to_word_array(av, " ");
    list->y = 0;
    list->i = 0;
    list->j = 0;
    list->new = NULL;
    list->path = NULL;
    list->name = NULL;
    list->name_dir = NULL;
    list->star = 0;
    list = execute(list);
    return list;
}

char *star(char *av)
{
    int nb = 0, j = 0, c = 0, e = 0;
    t_list *list = init(av);
    if (list->star == 0){
        for (int i = 0; list->new[i] != NULL; i++)
            c += strlen(list->new[i]);
        char *str = malloc(sizeof(char) * (c + 1));
        return in_str(list, str, e);
    }
    char **dest = supr_star(list, nb, j);
    for (int i = 0; dest[i] != NULL; i++)
        for (int j = 0; dest[i][j] != 0; j++)
            c++;
    char *str = malloc(sizeof(char) * (c + 1));
    for (int i = 0; dest[i] != NULL; i++) {
        for (int j = 0; dest[i][j] != 0; j++, e++)
            str[e] = dest[i][j];
        str[e] = ' ';
        e++;
    }
    str = clean_str(str); return str;
}
