/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** parse_env.c
*/

#include "my.h"
#include "my_list.h"
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

void check_defaults(linked_list_t *env);

void clean_str(char *rd_buf, size_t n);

void set_value(linked_list_t *list, char *var, char *val);

char *get_env_var(linked_list_t *env, char const *var);

void parse_env(char **env, linked_list_t *env_cpy)
{
    char **tmp = NULL;

    tmp = my_sep_array(env[0], '=');
    env_cpy->first->var = tmp[0];
    env_cpy->first->value = tmp[1];
    free(tmp);
    for (int i = 1; env[i]; i++) {
        tmp = my_sep_array(env[i], '=');
        push_first(env_cpy, tmp[0], tmp[1]);
        free(tmp);
    }
}