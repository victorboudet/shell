/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell1-victor.boudet
** File description:
** my_revstr
*/

#include "shell.h"

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    char *dest = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++) dest[i] = str[len - i - 1];
    dest[len] = '\0';
    return dest;
}
