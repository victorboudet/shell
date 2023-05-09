/*
** EPITECH PROJECT, 2023
** redirect
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdlib.h>
    #include <sys/types.h>
    #include <unistd.h>
    #include <sys/wait.h>
    #include <stdio.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <dirent.h>
    #include <stdio.h>
    #include "shell.h"

    typedef struct s_list {
        char **new;
        int y;
        int i;
        int j;
        char *name;
        char *name_dir;
        char *path;
        char **commande;
        int star;
        struct dirent *ent;
    } t_list;

    char **str_to_word_array(char *str, char *delim);
    char *clean_str(char *str);
    int str_compare(char *str1, char *str2);
    char *end_string(char *buffer);
    t_list *execute(t_list *list);
    t_list *disp_star_bis(t_list *list);
    t_list *loop(t_list *list);
    int tab_len(char **tab);
    char *supr(char *src, char del);
    t_list *loop_bis(t_list *list);
    char **supr_star(t_list *list, int nb, int j);
    char *in_str(t_list *list, char *str, int e);

#endif /* !MY_H_ */
