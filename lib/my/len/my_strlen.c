/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-kylian.labrador
** File description:
** my_strlen
*/

#include "my.h"

ssize_t my_strlen(const char *str)
{
    ssize_t i = 0;

    if (str == NULL)
        return 0;
    for (i = 0; str[i] != '\0'; i++);
    return i;
}
