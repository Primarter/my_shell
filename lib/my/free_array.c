/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** free_array.c
*/

#include <stdlib.h>
#include <unistd.h>

void free_array(void *array)
{
    void **arr = (void **)array;

    for (int i = 0; arr[i]; i++) {
        free(arr[i]);
    }
    free(arr);
}