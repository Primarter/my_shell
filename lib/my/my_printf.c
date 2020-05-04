/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printf.c
*/

#include "../../include/my.h"

static array_t func[13] =
{
    {'p', my_flag_p},
    {'x', my_flag_x},
    {'X', my_flag_bigx},
    {'b', my_flag_b},
    {'o', my_flag_o},
    {'%', my_flag_mod},
    {'m', my_flag_m},
    {'c', my_flag_c},
    {'S', my_flag_bigs},
    {'s', my_flag_s},
    {'i', my_flag_d_i},
    {'d', my_flag_d_i},
    {'u', my_flag_u},
};

void check(char c, va_list ap)
{
    for (int i = 0; i < 13; i += 1) {
        if (c == func[i].c) {
            func[i].ptr(ap);
            return;
        }
    }
    write(1, "%", 1);
    write(1, &c, 1);
}

void handle_percentage(char c, int *i)
{
    if (c == '%') {
        *i += 1;
        write(1, &c, 1);
    }
}

int my_printf(char *str, ...)
{
    va_list ap;

    va_start(ap, str);
    if (str[0] != '%' && str[0] != '\0')
        write(1, &(str[0]), 1);
    for (int i = 0; str[i]; i += 1) {
        while (str[i] == '%') {
            i += 1;
            check(str[i], ap);
            handle_percentage(str[i], &i);
        }
        if (str[i + 1] != '%' && str[i + 1])
            write(1, &(str[i + 1]), 1);
    }
    va_end(ap);
    return (0);
}