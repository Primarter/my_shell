/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** commands.c
*/

#include "basic.h"

int env_cmd(char **cmd, linked_list_t *list, linked_list_t *penv)
{
    (void)list;
    if (array_len(cmd) > 1) {
        my_printf("env: '%s': No such file or directory\n", cmd[1]);
        return (0);
    }
    show_list(penv);
    return (0);
}

int setenv_cmd(char **cmd, linked_list_t *list, linked_list_t *penv)
{
    if (!cmd || array_len(cmd) > 3) {
        write(2, "setenv: Too many arguments.", 27);
        return (84);
    }
    if (array_len(cmd) == 1) {
        show_list(penv);
        return (0);
    }
    if (alphanum_test(cmd[1])) {
        write(1, "setenv: ", 8);
        write(1, "Variable name must contain alphanumeric characters.\n", 52);
        return (84);
    }
    if (immutable_test(cmd[1]))
        set_list(list, cmd);
    set_list(penv, cmd);
    return (0);
}

int unsetenv_cmd(char **cmd, linked_list_t *list, linked_list_t *penv)
{
    for (int i = 1; cmd[i]; i++) {
        remove_var(cmd[i], penv);
        if (immutable_test(cmd[i])) {
            remove_var(cmd[i], list);
        }
    }
    return (0);
}

int exit_cmd(char **cmd, linked_list_t *list, linked_list_t *penv)
{
    (void)list;
    (void)penv;
    if (array_len(cmd) > 2) {
        write(2, "Wrong syntax\n", 13);
        return (84);
    }
    if (array_len(cmd) == 1)
        exit(0);
    for (int i = 0; cmd[1][i]; i++) {
        if (cmd[1][i] > 57 && cmd[1][i] < 48 && cmd[1][i] != '-') {
            write(2, "Bad formed number\n", 18);
            return (84);
        }
    }
    my_printf("exit\n");
    exit(my_getnbr(cmd[1]));
}

int cd_cmd(char **cmd, linked_list_t *list, linked_list_t *penv)
{
    char *home = "/home";

    if (array_len(cmd) > 2) {
        write(2, "cd: Too many arguments.", 23);
        return (84);
    }
    if (array_len(cmd) == 1) {
        home = get_env_var(list, "HOME") ? get_env_var(list, "HOME") : home;
        return (cd(home, list, penv));
    }
    if (array_len(cmd) == 2)
        return (cd(cmd[1], list, penv));
    return (84);
}