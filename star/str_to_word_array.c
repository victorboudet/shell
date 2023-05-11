/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell1-bastien.tiffy
** File description:
** str_to_word_array
*/

#include "my.h"

char **str_to_word_array(char *str, char *delim)
{
    int i, j = 0;
    int count = 0;
    int length = my_strlen(str);

    str = clean_str(str);
    for (i = 0; i < length; i++) {
        if (str[i] == delim[0]) {
            count++;
        }
    }
    char** words = (char**) malloc(sizeof(char*) * (count + 2));
    j = 0;
    words[j] = strtok(str, delim);
    while (words[j] != NULL) {
        j++;
        words[j] = strtok(NULL, delim);
    }
    return words;
}
