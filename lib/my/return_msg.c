/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** return_msg.c
*/

#include <unistd.h>
#include <stdbool.h>

bool return_msg(char const *msg, bool return_value, int const fd)
{
    int len = 0;
    ssize_t w = 0;

    for (; msg && msg[len]; len++);
    if (msg && fd >= 0)
        w = write(fd, msg, len);
    else
        w = write(2, "Return message error, check fd and msg\n", 39);
    if (w == -1)
        write(2, "Write error\n", 12);
    return (return_value);
}