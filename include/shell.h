/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** shell.h
*/

#ifndef SHELL_H_
    #define SHELL_H_

    #include "my_list.h"

    typedef struct shell_s {
        linked_list_t *env;
        linked_list_t *penv;
        int lret;
    } shell_t;

#endif