/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-kylian.labrador
** File description:
** malloc_2d
*/

#include "my.h"

char **malloc_2d_char(ssize_t x, ssize_t y)
{
    char **array = malloc(sizeof(char *) * (y + 1));

    if (array == NULL)
        return NULL;
    for (ssize_t i = 0; i < y; i++) {
        array[i] = malloc(sizeof(char) * (x + 1));
        if (array[i] == NULL)
            return NULL;
        for (ssize_t j = 0; j < x; j++)
            array[i][j] = '\0';
    }
    array[y] = NULL;
    return array;
}
