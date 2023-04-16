/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-kylian.labrador
** File description:
** my_strncomp
*/

#include <criterion/criterion.h>

int my_strncomp(const char *str1, const char *str2, int n);

Test(my_strncomp, test1) {
    char *str1 = "Hello";
    char *str2 = "Hello";
    int result = my_strncomp(str1, str2, 5);
    cr_assert_eq(result, 1);
}
