/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-kylian.labrador
** File description:
** my_double_array
*/

#include "my.h"

ssize_t my_2darray_len(char **array)
{
    ssize_t i = 0;

    for (i = 0; array[i] != NULL; i++);
    return i;
}
