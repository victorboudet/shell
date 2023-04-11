/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell1-victor.boudet
** File description:
** init_env
*/

#include "shell.h"

char **env_fonc(int value, char **array)
{
    static char **env = NULL;

    switch (value) {
        case 0:
            env = array;
            break;
        case 1:
            return env;
            break;
    }
    return NULL;
}

void init_env(char **env)
{
    env_fonc(0, env);
}

int remove_env(char *name)
{
    char **env = env_fonc(1, NULL);
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncomp(env[i], name, my_strlen(name))) {
            env_fonc(0, remove_row(env, i));
            return 0;
        }
    }
    return 0;
}

void add_env(char *name, char *value)
{
    char **array = get_env();
    int i = 0;
    int enter = 0;
    char **new = malloc(sizeof(char *) * (array_len(array) + 3));

    for (i = 0; array[i] != NULL; i++) {
        if (my_strncomp(array[i], name, my_strlen(name))) {
            new[i] = my_strcat(my_strcat(name, "="), value);
            enter = 1;
        } else {
        new[i] = array[i];
        }
    }
    if (enter == 0)
        new[i] = my_strcat(my_strcat(name, "="), value);
    new[i + 1] = NULL;
    env_fonc(0, new);
}

char **get_env(void)
{
    return env_fonc(1, NULL);
}
