/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-kylian.labrador
** File description:
** my_print_array
*/

#include <criterion/criterion.h>

bool my_print_array(char **array);

Test(my_print_array, test1) {
    char *array[3] = {"Hello", "World", NULL};
    cr_assert_eq(my_print_array(array), true);
}
