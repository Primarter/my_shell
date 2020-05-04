/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** match_str.c
*/

#include "my.h"

bool match_str(char const *string, int idx, char *sep)
{
    int i = 0;

    for (; sep[i] && string[idx] && string[idx] == sep[i]; i++)
        idx++;
    return (i == my_strlen(sep));
}