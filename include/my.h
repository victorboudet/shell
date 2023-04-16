/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-kylian.labrador
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <sys/stat.h>
    #include <stdbool.h>

void my_print_3darray(char ***array);
bool my_print_array(char **array);
int my_putchar(char c);
void my_putnbr(int nb);
bool my_putstr(const char *str);

ssize_t my_2darray_len(char **array);
ssize_t my_3darray_len(char ***array);
ssize_t my_strlen(const char *str);

char **malloc_2d_char(ssize_t x, ssize_t y);

char *my_revstr(char *str);
char *my_strcat(char *first, char *second);
int my_str_comp(const char *str1, const char *str2);
bool my_strcpy(char *dest, const char *src);
int my_strncomp(const char *str1, const char *str2, int n);

#endif /* !MY_H_ */
