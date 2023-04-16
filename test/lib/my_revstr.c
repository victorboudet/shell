/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-kylian.labrador
** File description:
** my_revstr
*/

#include <criterion/criterion.h>

char *my_revstr(char *str);

Test(my_revstr, test1) {
    char *str = "Hello";
    char *result = my_revstr(str);
    cr_assert_str_eq(result, "olleH");
}
