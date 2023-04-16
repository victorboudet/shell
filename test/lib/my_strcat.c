/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-kylian.labrador
** File description:
** my_strcat
*/

#include <criterion/criterion.h>

char *my_strcat(char *first, char *second);

Test(my_strcat, test1) {
    char *first = "Hello";
    char *second = "World";
    char *result = my_strcat(first, second);
    cr_assert_str_eq(result, "HelloWorld");
}
