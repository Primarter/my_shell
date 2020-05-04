/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** test.c
*/

#include "basic.h"

bool ignore_nested_str(char const *str, int *i)
{
    for (; str[*i] == '\"'; (*i)++)
        if (!str[*i])
            return (false);
    return (true);
}

bool redirection_error(char const *str)
{
    int c[3] = {0, 0, 0};

    for (int i = 0; str[i]; i++) {
        if (match_str(str, i, "<<") || match_str(str, i, ">>"))
            i++;
        if (!ignore_nested_str(str, &i))
            return (return_msg("Unclosed quote\n", true, 2));
        if ((str[i] == '|' && c[OUT]) || ((str[i] == '>') && c[OUT]))
            return (return_msg("Ambiguous output redirect.\n", true, 2));
        else {
            c[PIPE] = str[i] == '|' ? c[PIPE] + 1 : c[PIPE];
            c[OUT] = str[i] == '>' ? c[OUT] + 1 : c[OUT];
        }
        if ((str[i] == '<') && (c[PIPE] || c[IN]))
            return (return_msg("Ambiguous input redirect.\n", true, 2));
        else if (str[i] == '<')
            c[IN]++;
    }
    return (false);
}

char *get_next_word(char const *str, int idx)
{
    size_t len = 0;
    char *word = NULL;

    for (; str[idx] && !SPACE(str[idx + len]); idx++);
    for (; str[idx] && SPACE(str[idx]); idx++);
    for (; str[idx + len] && !SPACE(str[idx + len]); len++);
    word = malloc(sizeof(char) * (len + 1));
    word[len] = 0;
    for (int i = 0; str[idx + i] && !SPACE(str[idx + i]); i++)
        word[i] = str[idx + i];
    return (word);
}

char *rm_from_n(char *str, int idx, int offset)
{
    int len = my_strlen(str);
    char *cleansed = malloc(sizeof(char) * (len - offset + 1));
    int count = 0;

    cleansed[len - offset] = 0;
    for (int i = 0; str[i] && count < len - offset; i++) {
        if (i == idx)
            i += offset;
        if (count < len - offset && i < len)
            cleansed[count++] = str[i];
    }
    free(str);
    return (cleansed);
}

command_t get_cmd_struct_from_str(char *str)
{
    command_t cmd = {};

    if (redirection_error(str))
        return ((command_t){});
    str = get_and_rm_infile(&cmd, str);
    if (!str_not_empty(str))
        return ((command_t){});
    str = get_and_rm_outfile(&cmd, str);
    if (!str_not_empty(str))
        return ((command_t){});
    cmd.cmds = my_sep_array(str, '|');
    cmd.nb_cmds = array_len(cmd.cmds);
    return (cmd);
}