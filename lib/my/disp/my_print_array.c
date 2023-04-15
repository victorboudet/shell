/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-kylian.labrador
** File description:
** my_print_array
*/

#include "my.h"

bool my_print_array(char **array)
{
    int i = 0;
    int len = 0;

    if (array == NULL)
        return false;
    len = my_2darray_len(array);
    for (i = 0; i < len; i++) {
        my_putstr(array[i]);
        my_putchar('\n');
    }
    return true;
}
