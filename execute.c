/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-kylian.labrador
** File description:
** execute
*/

#include "shell.h"

const launch_t opt[] =
{
    {"env", my_env},
    {"exit", my_exit},
    {"cd", my_cd},
    {"setenv", my_setenv},
    {"unsetenv", my_unsetenv},
    {NULL, my_exec},
};

int last_exec(char **arg)
{
    int i = 0;
    for (i = 0; opt[i].name != NULL ; i++) {
        if (my_str_comp(arg[0], opt[i].name)) {
            break;
        }
    }
    return opt[i].ptr(arg);
}
