/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** built_in.c
*/


#include "basic.h"

static const func_tab_t tab[6] =
{
    {"cd", cd_cmd},
    {"env", env_cmd},
    {"setenv", setenv_cmd},
    {"unsetenv", unsetenv_cmd},
    {"exit", exit_cmd},
    {NULL, NULL}
};

int check_built_in(char **cmd, linked_list_t *env, linked_list_t *penv)
{
    for (int i = 0; tab[i].str; i++) {
        if (!(my_strcmp(tab[i].str, cmd[0])))
            return (tab[i].func(cmd, env, penv));
    }
    return (-1);
}

void print_exec_errors(char *prgrm)
{
    my_printf("%s: %s.", prgrm, strerror(errno));
    if (!my_strcmp(strerror(errno), "Exec format error"))
        my_printf(" Wrong Architecture.");
    write(1, "\n", 1);
    exit(84);
}

int exec_prgrm(char **prgrm, linked_list_t *env)
{
    int status = 0;
    int pid = fork();

    if (!pid) {
        execve(prgrm[0], prgrm, get_env_as_array(env));
        print_exec_errors(prgrm[0]);
    }
    return (status);
}

int choose_exec(char **prgrm, linked_list_t *env)
{
    char **path = parse_path(get_env_var(env, "PATH"));

    for (int i = 0; path && path[i]; i++) {
        if (!(access(my_strcat(path[i], prgrm[0]), X_OK))) {
            prgrm[0] = my_strcat(path[i], prgrm[0]);
            return (exec_prgrm(prgrm, env));
        }
    }
    if (!access(prgrm[0], X_OK)) {
        return (exec_prgrm(prgrm, env));
    }
    my_printf("%s: Command not found.\n", prgrm[0]);
    return (84);
}