/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-kylian.labrador
** File description:
** my_strcomp
*/

#include <criterion/criterion.h>

int my_str_comp(const char *str1, const char *str2);

Test(my_strcomp, test1) {
    char *str1 = "Hello";
    char *str2 = "Hello";
    int result = my_str_comp(str1, str2);
    cr_assert_eq(result, 1);
}
