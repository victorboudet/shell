/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell1-victor.boudet
** File description:
** my_putnbr
*/

#include "shell.h"

void my_putnbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb < 10) {
        my_putchar(nb + '0');
    } else {
        my_putnbr(nb / 10);
        my_putchar(nb % 10);
    }
}
