/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell1-victor.boudet
** File description:
** my_cd
*/

#include "shell.h"
#include <string.h>

char *get_varenv(char *name)
{
    char **env = get_env();
    int i = 0;
    char *home = NULL;

    while (env[i] != NULL) {
        if (strncmp(env[i], name, strlen(name))) {
            home = env[i];
            break;
        }
        i++;
    }
    if (home == NULL)
        return get_varenv("HOME");
    return home;
}

char *crop_b(char *str, int nb)
{
    char *new = malloc(sizeof(char) * (strlen(str) - nb + 1));
    int j = 0;

    for (j = 0; str[nb] != '\0'; nb++, j++) {
        new[j] = str[nb];
    }
    new[j] = '\0';
    return new;
}

int is_file(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

void two_str(char *str1, char *str)
{
    my_putstr(str1);
    my_putstr(str);
}

int my_cd(char **arg)
{
    if (arg[1] == NULL) {
        arg[1] = crop_b(get_varenv("HOME"), 5);
    } else if (arg[2] != NULL) {
        my_putstr("cd: Too many arguments.\n");
        return 1;
    }
    if (arg[1][0] == '-' && arg[1][1] == '\0')
        arg[1] = crop_b(get_varenv("OLDPWD"), 7);
    add_env("OLDPWD", getcwd(NULL, 0));
    int a = chdir(arg[1]);
    add_env("PWD", getcwd(NULL, 0));
    if (a == -1) {
        if (is_file(arg[1]))
            two_str(arg[1], ": Not a directory.\n");
        else
            two_str(arg[1], ": No such file or directory.\n");
        return 1;
    }
    return 0;
}
