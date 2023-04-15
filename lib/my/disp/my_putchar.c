/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-kylian.labrador
** File description:
** my_putchar
*/

#include <unistd.h>

int my_putchar(char c)
{
    return write(1, &c, 1);
}
