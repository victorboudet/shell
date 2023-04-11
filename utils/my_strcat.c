/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell1-victor.boudet
** File description:
** my_strcat
*/

#include "shell.h"

char *my_strcat(char *first, char *second)
{
    int a = my_strlen(second);
    int c = my_strlen(first);
    char *new = malloc(sizeof(char) * (a + c + 1));
    int i = 0;

    for (i = 0; i < c; i++) {
        new[i] = first[i];
    }
    for (int j = 0; j < a; j++, i++) {
        new[i] = second[j];
    }
    new[i] = '\0';
    return new;
}

void my_strcpy(char *dest, const char *src)
{
    int i = 0;

    for (; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}
