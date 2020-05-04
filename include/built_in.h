/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** built_in.h
*/

#ifndef BUILT_IN_H_
    #define BUILT_IN_H_

    #include "my_list.h"

    typedef struct func_tab_s {
        char *str;
        int (*func)(char **, linked_list_t *, linked_list_t *);
    } func_tab_t;

#endif