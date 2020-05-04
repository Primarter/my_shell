/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** help.c
*/

#include <unistd.h>

void disp_help_env(void)
{
    write(1, "USAGE: env [OPTION]\n\tenv displays the current env ", 50);
    write(1, "variables.\n\nOPTION:\n\t-h, --help\tDisplay this help\n", 49);
}

void disp_help_setenv(void)
{
    write(1, "USAGE: env [VARIABLE] [VALUE]\n\tsetenv without arguments", 55);
    write(1, "displays the current environment variables.\n\tOtherwise, ", 56);
    write(1, "setenv sets or changes an environmental value,\n\tThe new", 55);
    write(1, "variable has the name [VARIABLE] and the value [VALUE]\n", 55);
}