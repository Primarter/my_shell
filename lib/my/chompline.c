/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** chompline.c
*/

#include <stdio.h>
#include <unistd.h>

ssize_t chompline(char **lineptr, size_t *n, FILE *stream)
{
    char *line = NULL;
    ssize_t ret = getline(&line, n, stream);
    size_t len = 0;

    if (ret < 0) {
        *n = 0;
        return (-1);
    }
    for (; line[len]; len++);
    if (line[len - 1] == '\n')
        line[len - 1] = 0;
    *lineptr = line;
    return (ret);
}