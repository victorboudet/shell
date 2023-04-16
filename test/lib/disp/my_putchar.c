/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-kylian.labrador
** File description:
** my_putchar
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_putchar(char c);

Test(my_putchar, normal_character) {
    cr_redirect_stdout();
    my_putchar('a');
    cr_assert_stdout_eq_str("a");
}
