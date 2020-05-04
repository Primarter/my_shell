/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** parsng.c
*/

#include "basic.h"

char **parse_cmd_values(char **cmd, int lret)
{
    if (!cmd) {
        return (NULL);
    }
    for (int i = 0; cmd[i]; i++) {
        if (!my_strcmp(cmd[0], "cd") && !my_strcmp(cmd[i], "~"))
            cmd[i] = get_home();
        if (!my_strcmp(cmd[i], "$?"))
            cmd[i] = my_itos(lret);
    }
    return (cmd);
}

void basic_exec(char *rd_buf, shell_t *shell)
{
    char **cmd = parse_cmd_values(my_word_array(rd_buf), shell->lret);

    if (!rd_buf || rd_buf[0] == '\n' || !rd_buf[0] || cmd == NULL) {
        shell->lret = 0;
        return;
    }
    shell->lret = check_built_in(cmd, shell->env, shell->penv);
    if (shell->lret != -1)
        return;
    shell->lret = choose_exec(cmd, shell->env);
}

char **parse_path(char *path)
{
    char *tmp = malloc(sizeof(char));
    char **array = malloc(sizeof(char *));

    tmp[0] = 0;
    array[0] = NULL;
    if (!path)
        return (NULL);
    for (int i = 0; path[i]; i++) {
        for (;path[i] && path[i] != ':'; i++)
            tmp = my_append(tmp, path[i]);
        tmp = my_append(tmp, '/');
        if (path[i - 1] && path[i - 1] != ':') {
            array = my_append_array(array, tmp);
        }
        if (!path[i])
            break;
        tmp = malloc(sizeof(char));
        tmp[0] = 0;
    }
    return (array);
}