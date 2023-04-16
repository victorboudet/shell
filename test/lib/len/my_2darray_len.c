/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-kylian.labrador
** File description:
** my_double_array
*/

#include <criterion/criterion.h>

ssize_t my_2darray_len(char **array);

Test(my_2darray_len, test1) {
    char *array[3] = {"Hello", "World", NULL};
    cr_assert_eq(my_2darray_len(array), 2);
}
