/*
** EPITECH PROJECT, 2019
** lib
** File description:
** str_not_empty.c
*/

int str_not_empty(char const *str)
{
    if (!str)
        return (0);
    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            return ((int)str[i]);
    }
    return (0);
}