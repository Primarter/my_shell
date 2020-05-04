/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** handle_env.c
*/

#include "my.h"
#include "my_list.h"

char *get_env_var(linked_list_t *env, char const *var)
{
    node_t *current = NULL;

    if (!env)
        return (NULL);
    current = env->first;
    while (current && my_strcmp(current->var, var))
        current = current->next;
    if (!current)
        return (NULL);
    return (current->value);
}

char **get_env_as_array(linked_list_t *env)
{
    size_t len = size_list(env);
    char **env_array = malloc(sizeof(char *) * (len + 1));
    char *tmp = NULL;
    node_t *current = env->first;

    if (!env_array)
        return (NULL);
    env_array[len] = NULL;
    for (size_t i = 0; current; i++) {
        tmp = my_strcat(current->var, "=");
        tmp = my_strcat(tmp, current->value);
        env_array[i] = tmp;
        tmp = NULL;
        current = current->next;
    }
    return (env_array);
}