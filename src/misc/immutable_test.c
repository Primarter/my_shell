/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** immutable_test.c
*/

#include "my.h"

int immutable_test(char *tested)
{
    if (my_strcmp("PWD", tested) && my_strcmp(tested, "OLDPWD"))
        return (1);
    return (0);
}