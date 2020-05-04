/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** switch_list.c
*/

#include "my_list.h"

void test_first(linked_list_t *list, node_t *current1, node_t *current2)
{
    if (current1 == list->first)
        list->first = current2;
    else if (current2 == list->first)
        list->first = current1;
    if (current1 == list->last)
        list->last = current2;
    else if (current2 == list->last)
        list->last = current1;
}

void switch_place(linked_list_t *list, char *var1, char *var2)
{
    node_t *current1 = list->first;
    node_t *current2 = list->first;
    node_t *tmp = NULL;

    while (!(my_strcmp(current1->var, var1)))
        current1 = current1->next;
    while (!(my_strcmp(current2->var, var2)))
        current2 = current2->next;
    test_first(list, current1, current2);
    tmp = current1->next;
    current1->next = current2->next;
    current2->next = tmp;
    tmp = current1->previous;
    current1->previous = current2->previous;
    current2->previous = tmp;
}

void swap_values(linked_list_t *list, char *var1, char *var2)
{
    node_t *current1 = list->first;
    node_t *current2 = list->first;
    char *tmp = NULL;

    while ((my_strcmp(current1->var, var1)))
        current1 = current1->next;
    while ((my_strcmp(current2->var, var2)))
        current2 = current2->next;
    tmp = current1->value;
    current1->value = current2->value;
    current2->value = tmp;
}