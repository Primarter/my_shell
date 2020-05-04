/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** alphanum_test.c
*/

int test(char c)
{
    if (c >= 'a' && c <= 'z')
        return (0);
    if (c >= 'A' && c <= 'Z')
        return (0);
    if (c == '_')
        return (0);
    return (1);
}

int alphanum_test(char *str)
{
    for (int i = 0; str[i]; i++)
        if (test(str[i]))
            return (1);
    return (0);
}