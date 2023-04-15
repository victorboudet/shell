/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-kylian.labrador
** File description:
** my_strcomp
*/

#include "my.h"

int my_str_comp(const char *str1, const char *str2)
{
    if (my_strlen(str1) != my_strlen(str2))
        return 0;
    for (int i = 0; str1[i] && str2[i]; i++) {
        if (str1[i] != str2[i])
                return 0;
    }
    return 1;
}
