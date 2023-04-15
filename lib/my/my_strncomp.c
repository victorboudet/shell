/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-kylian.labrador
** File description:
** my_strncomp
*/

#include "my.h"

int my_strncomp(const char *str1, const char *str2, int n)
{
    if (str1 == NULL || str2 == NULL)
        return 0;
    for (int i = 0; str1[i] && str2[i] && i < n; i++) {
        if (str1[i] != str2[i])
                return 0;
    }
    return 1;
}
