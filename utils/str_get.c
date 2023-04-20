/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell1-victor.boudet
** File description:
** str_get
*/

#include "shell.h"

char *my_str_get_begin(char *str, char c)
{
    int i = 0;
    char *new = NULL;

    if (str == NULL)
        return NULL;
    for (; str[i] != c && str[i] != '\0'; i++);
    new = malloc(sizeof(char) * (i + 1));
    for (int j = 0; j < i; j++) {
        new[j] = str[j];
    }
    return new;
}

char *my_str_get_end(char *str, char c)
{
    int i = 0;
    char *new = NULL;
    int slen = my_strlen(str);

    if (str == NULL)
        return NULL;
    for (; str[i] != c && str[i] != '\0'; i++);
    if (slen - i <= 1)
        return NULL;
    new = malloc(sizeof(char) * (slen - i));
    for (int j = 0; str[i + 1] != '\0'; i++, j++) {
        new[j] = str[i + 1];
    }
    return new;
}

char **remove_row(char **array, int row)
{
    int i = 0;
    int j = 0;
    char **new = malloc(sizeof(char *) * (array_len(array)));

    for (i = 0; array[i] != NULL; i++) {
        if (i != row) {
            new[j] = array[i];
            j++;
        }
    }
    new[j] = NULL;
    return new;
}

void print_env(void)
{
    char **array = get_env();

    for (int i = 0; array[i] != NULL; i++) {
        my_putstr(array[i]);
        my_putchar('\n');
    }
}

void print_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        my_putstr(array[i]);
        my_putchar('-');
    }
    my_putchar('\n');
}
