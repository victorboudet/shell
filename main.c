/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell1-victor.boudet
** File description:
** main
*/

#include "shell.h"
void print_array(char **array);
char **get_arg(char *str, int a);
char **malloc_2d(int x, int y);

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

int check_sep(char *str)
{
    if (*str == '|')
        return 1;
    if (*str == '>' && *(str + 1) == '>')
        return 2;
    if (*str == '<' && *(str + 1) != '<')
        return 3;
    if (*str == '>')
        return 4;
    if (*str == '<')
        return 5;
    return 0;
}

int mysh(void)
{
    char *line = NULL;
    size_t lline = 0;
    int status = 1;
    set_signal();
    int ret = 0;
    while (status) {
        if (isatty(0))
            print_tty();
        getline(&line, &lline, stdin);
        if (line[0] == 0 || line == NULL || (line[0] == '\n' && !isatty(0)))
            break;
        if (line[0] == '\n') continue;
        ret = check_line(line, ret);
        line = NULL;
    }
    return ret;
}

int main(int ac, char **av, char **env)
{
    if (ac != 1)
        return 84;
    init_env(env);
    int a = mysh();
    return a;
    (void) av;
}
