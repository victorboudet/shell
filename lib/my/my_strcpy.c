/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-kylian.labrador
** File description:
** my_strcpy
*/

#include "my.h"

bool my_strcpy(char *dest, const char *src)
{
    int i = 0;
    if (dest == NULL || src == NULL)
        return false;
    if (my_strlen(dest) < my_strlen(src))
        return false;
    for (; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return true;
}
