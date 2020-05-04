/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** handle_list.c
*/

#include "my_list.h"
#include <unistd.h>

size_t size_list(linked_list_t *list)
{
    node_t *now = NULL;
    size_t len = 0;

    if (!list) {
        return (0);
    }
    now = list->first;
    while (now) {
        len++;
        now = now->next;
    }
    return (len);
}