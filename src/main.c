/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** main.c
*/

#include "basic.h"

void clean_str(char *rd_buf, size_t n)
{
    for (size_t i = 0; i < n; i++)
        rd_buf[i] = 0;
}

char *parpwd(char *str)
{
    int i = my_strlen(str) - 1;
    char *cut_str = NULL;

    for (; i > 0 && str[i - 1] != '/'; i--);
    cut_str = malloc(sizeof(char) * (my_strlen(str) - i + 1));
    for (int j = 0; str[i]; i++) {
        cut_str[j] = str[i];
        cut_str[++j] = 0;
    }
    return (cut_str);
}

void main_loop(char **env)
{
    char *rd_buf = NULL;
    shell_t shell = {get_env(env), get_env(env), 0};
    size_t getl = 0;

    do {
        signal(SIGINT, SIG_IGN);
        execute_line(rd_buf, &shell);
        if (isatty(0)) {
            my_printf("\033[32m%s\033[91m @ ", get_env_var(shell.env, "USER"));
            my_printf("\033[96m%s> \033[0m", get_env_var(shell.env, "PWD"));
        }
    } while (chompline(&rd_buf, &getl, stdin) > 0);
    if (isatty(0))
        write(1, "exit\n", 5);
}

int main(int argc, __attribute__((unused))char const *argv[], char **env)
{
    if (argc != 1)
        return (84);
    main_loop(env);
    return (0);
}
