/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell1-victor.boudet
** File description:
** my_put
*/

#include <stddef.h>
#include <unistd.h>
void print_array(char **array);

void my_putchar(const char c)
{
    write(1, &c, 1);
}

void my_putstr(const char *str)
{
    if (str == NULL)
        return;
    for (int i = 0; str[i]; i++) {
        write(1, &str[i], 1);
    }
}

void print_double_array(char ***array)
{
    for (int i = 0; array[i] != NULL; i++) {
        print_array(array[i]);
    }
}
