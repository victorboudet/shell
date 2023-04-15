/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-kylian.labrador
** File description:
** my_putstr
*/

#include "my.h"

bool my_putstr(const char *str)
{
    ssize_t len = 0;

    len = my_strlen(str);
    return write(1, str, len);
}
