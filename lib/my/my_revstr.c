/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-kylian.labrador
** File description:
** my_revstr
*/

#include "my.h"

char *my_revstr(char *str)
{
    ssize_t len = 0;
    char *dest = NULL;

    if (str == NULL)
        return NULL;
    len = my_strlen(str);
    dest = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++) dest[i] = str[len - i - 1];
    dest[len] = '\0';
    free(str);
    return dest;
}
