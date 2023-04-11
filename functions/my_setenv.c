/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell1-victor.boudet
** File description:
** my_setenv
*/

#include <shell.h>

// list_t *new_list(char **arg)
// {
//     list_t *new = malloc(sizeof(list_t));
//     new->name = arg[1];
//     new->value = arg[2];
//     new->next = NULL;
//     return new;
// }

int is_alpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}

int is_digit(char c)
{
    if ((c >= '0' && c <= '9') || c == '.' || c == '_')
        return 1;
    return 0;
}

int is_alphanum(char *str)
{
    if (!is_alpha(str[0]) && str[0] != '_') {
        my_putstr("setenv: Variable name must begin with a letter.\n");
        return 1;
    }
    for (int i = 0; str[i]; i++) {
        if (!is_alpha(str[i]) && !is_digit(str[i])) {
            my_putstr("setenv: Variable name must contain");
            my_putstr(" alphanumeric characters.\n");
            return 1;
        }
    }
    return 0;
}

int my_setenv(char **arg)
{
    int alen = array_len(arg);
    char *new = "";
    if (alen < 2) {
        print_env();
        return 0;
    }
    if (alen > 3) {
        my_putstr("setenv: Too many arguments.\n");
        return 1;
    }
    if (alen == 3) new = arg[2];
    if (is_alphanum(arg[1]))
        return 1;
    add_env(arg[1], new);
    return 0;
}

// char **add_row(char **array, char *str)
// {
//     int i = 0;
//     char **new = malloc(sizeof(char *) * (array_len(array) + 3));

//     for (i = 0; array[i] != NULL; i++) {
//         new[i] = array[i];
//     }
//     new[i] = str;
//     new[i + 1] = NULL;
//     return new;
// }

// char **change_row_str(char **array, char *new_str, int row)
// {
//     int i = 0;
//     char **new = malloc(sizeof(char *) * (array_len(array) + 1));

//     for (i = 0; array[i] != NULL; i++) {
//         if (i != row) {
//             new[i] = array[i];
//         } else {
//             new[i] = new_str;
//         }
//     }
//     new[i] = NULL;
//     return new;
// }
