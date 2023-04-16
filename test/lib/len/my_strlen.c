/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-kylian.labrador
** File description:
** my_strlen
*/

#include <criterion/criterion.h>

ssize_t my_strlen(const char *str);

Test(my_strlen, test1) {
    char *str = "Hello";
    ssize_t result = my_strlen(str);
    cr_assert_eq(result, 5);
}
