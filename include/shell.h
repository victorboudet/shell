/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell1-victor.boudet
** File description:
** shell
*/

#ifndef SHELL_H_
    #define SHELL_H_

    #include <stdlib.h>
    #include <stddef.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <signal.h>
    #include <stdbool.h>
    #include <wait.h>
    #include <dirent.h>
    #include <sys/stat.h>
    #include <string.h>
    #include <errno.h>

// typedef struct list_s list_t;
// struct list_s {
//     char *name;
//     char *value;
//     list_t *next;
// };

// typedef struct env_s {
//     list_t *l;
//     char **env;
//     int size;
// } env_t;

typedef struct launch_s {
    char *name;
    int (*ptr)(char **);
} launch_t;

typedef struct error_s {
    int code;
    char *msg;
} error_t;

typedef struct parse_s {
    int i;
    int j;
    bool in;
    char **dest;
    char *str;
} parse_t;

typedef struct format_s {
    char ***dest;
    int *tab;
} format_t;

// utils
//      my_puts.c
int last_exec(char **arg);
int check_line(char *line, int ret);
void my_putchar(const char c);
void my_putstr(const char *str);
void my_putnbr(int nb);
//      other
int my_strncomp(const char *str1, const char *str2, int n);
int my_str_comp(const char *str1, const char *str2);
int my_strlen(const char *str);
char **my_str_to_word_array(char *str);
char *my_strcat(char *first, char *second);
int array_len(char **array);
void my_strcpy(char *dest, const char *src);
int my_strstr_start_end(char *str, char *to_find, char *to_find2);
int my_strstr_start(char *str, char *to_find);
int my_strstr_end(char *str, char *to_find);

// env
// env_t *init_env(char **env);
// void print_env(env_t env);

// functions
int my_env(char **arg);
int my_exit(char **arg);
int my_cd(char **arg);
int my_exec(char **arg);
int my_setenv(char **arg);
int my_unsetenv(char **arg);

// signals
pid_t process(pid_t pid, bool act);
void set_signal(void);
void sigint_handler(int sig);
void segf_handler(int sig);

// char **change_row_str(char **array, char *new_str, int row);
// char **add_row(char **array, char *str);
char **remove_row(char **array, int row);
void print_env(void);

char **env_fonc(int value, char **array);
void init_env(char **env);
int remove_env(char *name);
void add_env(char *name, char *value);
char **get_env(void);
// void remove_env(int row);

char *star(char *av);

#endif /* !SHELL_H_ */
