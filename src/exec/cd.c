/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** cd.c
*/

#include "basic.h"

void change_pwd(char *dest, linked_list_t *env)
{
    if (!get_env_var(env, "OLDPWD") || !get_env_var(env, "PWD"))
        return;
    if (!my_strcmp(dest, "-")) {
        chdir(get_env_var(env, "OLDPWD"));
        swap_values(env, "PWD", "OLDPWD");
        return;
    }
    set_value(env, "OLDPWD", get_env_var(env, "PWD"));
    return (set_value(env, "PWD", dest));
}

int cd(char *dest, linked_list_t *env, linked_list_t *penv)
{
    char *cwd = malloc(sizeof(char) * 32778);

    clean_str(cwd, (size_t) 32278);
    if (chdir(dest) && my_strcmp(dest, "-")) {
        my_printf("%s: %s.\n", dest, strerror(errno));
        return (84);
    }
    getcwd(cwd, 32778);
    change_pwd(my_strcmp(dest, "-") ? cwd : dest, env);
    change_pwd(my_strcmp(dest, "-") ? cwd : dest, penv);
    return (0);
}