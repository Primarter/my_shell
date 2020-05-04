/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** init_list.c
*/

#include "my_list.h"

linked_list_t *init_list(void)
{
    linked_list_t *list = malloc(sizeof(*list));
    node_t *node = malloc(sizeof(*node));

    if (!list || !node)
        return (NULL);
    node->var = NULL;
    node->value = NULL;
    node->next = NULL;
    node->previous = NULL;
    list->first = node;
    list->last = node;
    return (list);
}

void push_first(linked_list_t *list, char *new_str, char *new_val)
{
    node_t *new = malloc(sizeof(*new));

    if (!new)
        return;
    new->var = new_str;
    new->value = new_val;
    list->first->previous = new;
    new->next = list->first;
    new->previous = NULL;
    list->first = new;
}

void append_node(linked_list_t *list, char *new_str, char *new_val)
{
    node_t *new = malloc(sizeof(*new));

    if (!new)
        return;
    list->last->next = new;
    new->var = new_str;
    new->value = new_val;
    new->previous = list->last;
    new->next = NULL;
    list->last = new;
}

void suppr_first(linked_list_t *list)
{
    node_t *suppr = NULL;

    if (!list) {
        return;
    }
    if (list->first) {
        suppr = list->first;
        list->first = list->first->next;
        list->first->previous = NULL;
        free(suppr->value);
        free(suppr->var);
        free(suppr);
    }
}

void show_list(linked_list_t *list)
{
    node_t *curr = list ? list->first : NULL;

    if (!list) {
        return;
    }
    curr = list->first;
    while (curr) {
        my_printf("%s=", curr->var);
        if (curr->value)
            my_printf("%s\n", curr->value);
        else
            write(1, "\n", 1);
        curr = curr->next;
    }
}