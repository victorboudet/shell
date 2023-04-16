/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-kylian.labrador
** File description:
** my_putstr
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

bool my_putstr(const char *str);

Test(my_putstr, should_print_hello) {
    cr_redirect_stdout();
    my_putstr("Hello");
    cr_assert_stdout_eq_str("Hello");
}
