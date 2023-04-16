/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell1-victor.boudet
** File description:
** my_putnbr
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void my_putnbr(int nb);

Test(my_putnbr, should_print_42) {
    cr_redirect_stdout();
    my_putnbr(42);
    cr_assert_stdout_eq_str("42");
}
