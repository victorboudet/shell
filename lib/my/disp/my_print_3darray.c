/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-kylian.labrador
** File description:
** my_print_3darray
*/

#include "my.h"

void my_print_3darray(char ***array)
{
    ssize_t i = 0;
    ssize_t j = 0;

    for (i = 0; array[i] != NULL; i++) {
        for (j = 0; array[i][j] != NULL; j++) {
            my_putstr(array[i][j]);
            my_putchar(' ');
        }
        my_putchar('\n');
    }
}
