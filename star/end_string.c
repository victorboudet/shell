/*
** EPITECH PROJECT, 2023
** minishell1.1.2
** File description:
** end_string
*/

#include "my.h"

char *end_string(char *buffer)
{
    for (int i = 0; i != my_strlen(buffer); i++)
        if (buffer[i] == '\n') {
            buffer[i] = 0;
            break;
        }
    return buffer;
}
