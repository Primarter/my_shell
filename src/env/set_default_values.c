/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** set_default_values.c
*/

#include "my_list.h"

char *get_env_var(linked_list_t *env, char const *var);

void clean_str(char *rd_buf, size_t n);

void set_value(linked_list_t *list, char *var, char *val);

void check_defaults(linked_list_t *env)
{
    char *cwd = malloc(sizeof(char) * 32778);

    clean_str(cwd, 32778);
    getcwd(cwd, 32778);
    if (!get_env_var(env, "PWD"))
        set_value(env, "PWD", cwd);
    else
        free(cwd);
    set_value(env, "OLDPWD", get_env_var(env, "PWD"));
}