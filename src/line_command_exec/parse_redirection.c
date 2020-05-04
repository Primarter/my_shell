/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** parse_redirection.c
*/

#include "basic.h"

void here_document(bool present, char **delimiter)
{
    char *line = NULL;
    size_t n = 0;
    char **res = NULL;

    if (!present || !str_not_empty(*delimiter))
        return;
    write(1, "? ", 2);
    while (chompline(&line, &n, stdin) != -1) {
        if (!my_strcmp(line, *delimiter)) {
            free(*delimiter);
            free(line);
            *delimiter = NULL;
            break;
        }
        res = my_append_array(res, line);
        write(1, "? ", 2);
    }
    for (int i = 0; res && res[i]; i++) {
        write(0, res[i], my_strlen(res[i]));
        write(0, "\n", 1);
    }
}

char *get_and_rm_infile(command_t *cmd, char *str)
{
    int idx = 0;
    int len = 0;

    for (int i = 0; str[i] && !idx; i++)
        if (str[i] == '<') {
            idx = i;
            cmd->infile = get_next_word(str, i);
            here_document(match_str(str, i, "<<"), &cmd->infile);
        }
    if (!cmd->infile)
        return (str);
    if (!str_not_empty(cmd->infile)) {
        write(2, "Missing name for redirect\n", 26);
        return ("");
    }
    for (; str[idx + len] && str[idx + len] == '<'; len++);
    for (; str[idx + len] && SPACE(str[idx + len]); len++);
    for (; str[idx + len] && !SPACE(str[idx + len]); len++);
    str = rm_from_n(str, idx, len);
    return (str);
}

char *get_and_rm_outfile(command_t *cmd, char *str)
{
    int idx = 0;
    int len = 0;

    for (int i = 0; str[i] && !idx; i++)
        if (str[i] == '>') {
            idx = i;
            cmd->outfile = get_next_word(str, i);
            cmd->out_mode = match_str(str, i, ">>");
        }
    if (!cmd->outfile)
        return (str);
    if (!str_not_empty(cmd->outfile)) {
        write(2, "Missing name for redirect\n", 26);
        return ("");
    }
    for (; str[idx + len] && str[idx + len] == '>'; len++);
    for (; str[idx + len] && SPACE(str[idx + len]); len++);
    for (; str[idx + len] && !SPACE(str[idx + len]); len++);
    str = rm_from_n(str, idx, len);
    return (str);
}