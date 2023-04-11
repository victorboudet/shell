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

int mysh(void)
{
    char *line = NULL;
    size_t lline = 0;
    int status = 1;
    set_signal();
    int ret = 0;

    while (status) {
        if (isatty(0))
            my_putstr("$> ");
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
