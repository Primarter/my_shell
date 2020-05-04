/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** unsetenv.c
*/

#include "my_list.h"

void suppr_node(node_t *node, linked_list_t *list)
{
    if (node->previous)
        node->previous->next = node->next;
    else
        list->first = node->next;
    if (node->var)
        free(node->var);
    if (node->value)
        free(node->value);
    free (node);
}

void remove_var(char *var, linked_list_t *list)
{
    node_t *current = list->first;

    while (current) {
        if (!(my_strcmp(current->var, var))) {
            suppr_node(current, list);
            return;
        }
        current = current->next;
    }
}