/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-kylian.labrador
** File description:
** my_strstr
*/

#include <stdio.h>
#include <string.h>

int my_strstr_end(char *str, char *to_find)
{
    return strcmp(str + (strlen(str) - strlen(to_find)), to_find);
}

int my_strstr_start(char *str, char *to_find)
{
    return strncmp(str, to_find, strlen(to_find));
}

int my_strstr_start_end(char *str, char *to_find, char *to_find2)
{
    return (my_strstr_start(str, to_find) + my_strstr_end(str, to_find2));
}
