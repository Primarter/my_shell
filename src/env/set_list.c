/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** set_list.c
*/

#include "my_list.h"

void set_list(linked_list_t *list, char **cmd)
{
    node_t *current = list->first;

    while (current->next) {
        if (!(my_strcmp(current->var, cmd[1]))) {
            current->value = cmd[2];
            return;
        }
        current = current->next;
    }
    push_first(list, cmd[1], cmd[2]);
}

void set_value(linked_list_t *list, char *var, char *val)
{
    node_t *current = list->first;

    while (current->next) {
        if (!(my_strcmp(current->var, var))) {
            current->value = val;
            return;
        }
        current = current->next;
    }
    push_first(list, var, val);
}

node_t *get_node(linked_list_t *list, char *var, char *val)
{
    node_t *crt = list->first;

    if (var == NULL && val == NULL)
        return (NULL);
    if (var == NULL) {
        while (crt && !my_strcmp(val, crt->value))
            crt = crt->next;
        return (crt);
    } else if (val == NULL) {
        while (crt && !my_strcmp(var, crt->var))
            crt = crt->next;
        return (crt);
    } else {
        while (crt && !my_strcmp(val, crt->value) && !my_strcmp(var, crt->var))
            crt = crt->next;
        return (crt);
    }
    return (NULL);
}