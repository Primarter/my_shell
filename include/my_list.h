/*
** EPITECH PROJECT, 2019
** mylist.h
** File description:
** linked list
*/


#ifndef MYLIST_H_
    #define MYLIST_H_

    #include <stdlib.h>
    #include <unistd.h>
    #include "my.h"

    typedef struct node_s
    {
        char *var;
        char *value;
        struct node_s *next;
        struct node_s *previous;
    } node_t;

    typedef struct linked_list_s
    {
        node_t *first;
        node_t *last;
    } linked_list_t;

    linked_list_t *init_list(void);
    void push_first(linked_list_t *list, char *new_str, char *new_val);
    void append_node(linked_list_t *list, char *new_str, char *new_val);
    void suppr_first(linked_list_t *list);
    void show_list(linked_list_t *list);
    size_t size_list(linked_list_t *list);

#endif