/*
** EPITECH PROJECT, 2023
** ter
** File description:
** main_bis
*/

#include "my.h"

t_list *loop_star(t_list *list)
{
    list->name = list->ent->d_name;
    if (list->path == NULL) {
        list->y++;
        list->new = realloc(list->new, sizeof(char *) * (list->y + 1));
        if (list->name_dir[0] != '.') {
            list->new[list->y] = strdup(list->name_dir);
            list->new[list->y] = strcat(list->new[list->y], list->ent->d_name);
            return list;
        }
        list->new[list->y] = strdup(list->ent->d_name);
        return list;
    }
    if (list->path == NULL || list->name == NULL)
        return list;
    list = loop_bis(list);
    return list;
}

t_list *disp_star_bis(t_list *list)
{
    DIR *dir;

    if (list->commande[list->i][list->j] != '*')
        return list;
    list->star = 1;
    if (str_to_word_array(list->commande[list->i], "/")[0][0] == '.') {
        list->name_dir =
        strdup(str_to_word_array(list->commande[list->i], "/")[1]);
    } else
        list->name_dir = strdup(".");
    list->path = list->commande[list->i];
    if ((dir = opendir(list->name_dir)) == NULL)
        return NULL;
    while ((list->ent = readdir(dir)) != NULL)
        list = loop_star(list);
    closedir(dir);
    return list;
}

t_list *execute(t_list *list)
{
    list->new = malloc(sizeof(char *) * (tab_len(list->commande) + 1));
    for (list->i = 0; list->commande[list->i] != NULL; list->i++) {
        list->new[list->y] = strdup(list->commande[list->i]);
        for (list->j = 0; list->commande[list->i][list->j] != '\0'; list->j++) {
            list = disp_star_bis(list);
        }
        list->y++;
    }
    list->new = realloc(list->new, sizeof(char *) * (list->y + 1));
    list->new[list->y] = NULL;
    return list;
}

char **supr_star(t_list *list, int nb, int j)
{
    for (int i = 0, j = 0; list->new[i] != NULL;) {
        if (list->new[i][j] == '*')
            nb = i;
        if (list->new[i][j] == 0) {
            j = 0;
            i++;
        }
        j++;
    }
    char **dest = malloc(sizeof(char *) * (tab_len(list->new)));
    for (int i = 0; list->new[i] != NULL; i++, j++) {
        if (j == nb + 1)
            i++;
        if (list->new[i] != NULL)
            dest[j] = strdup(list->new[i]);
    }
    dest[j] = NULL;
    return dest;
}

char *in_str(t_list *list, char *str, int e)
{
    for (int i = 0; list->new[i] != NULL; i++)
        for (int j = 0; list->new[i][j] != 0; j++, e++)
            str[e] = list->new[i][j];
    return str;
}
