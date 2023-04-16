/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-kylian.labrador
** File description:
** my_strcpy
*/

#include <criterion/criterion.h>
#include <stdlib.h>

void my_strcpy(char *dest, const char *src);

Test(my_strcpy, test1) {
    const char *src = "Hello";
    char *dest = malloc(strlen(src) + 1);
    my_strcpy(dest, src);
    cr_assert_str_eq(dest, "Hello");
    free(dest);
}
