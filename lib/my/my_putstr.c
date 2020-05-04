/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** print array
*/

#include <unistd.h>

void my_putstr(char const *str)
{
    size_t len = 0;

    for (; str && str[len]; len++);
    if (str)
        write(1, str, len);
    else
        write(1, "(null)", 6);
}
