/*
** EPITECH PROJECT, 2019
** bootstrap_world
** File description:
** array_len.c
*/

#include <stdlib.h>

size_t array_len(void *array)
{
    size_t len = 0;
    void **arr = array;

    if (!array)
        return (0);
    while (arr[len])
        len++;
    return (len);
}