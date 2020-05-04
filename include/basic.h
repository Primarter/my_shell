/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** basic.h
*/

#ifndef MAIN_H_
    #define MAIN_H_

    #define SPACE(c) (c == ' ' || c == '\t' || c == '\n')

    #include "my_list.h"
    #include "shell.h"
    #include "built_in.h"
    #include "my_signal.h"
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <sys/wait.h>
    #include <fcntl.h>
    #include <error.h>
    #include <signal.h>
    #include <errno.h>

    typedef struct command_s {
        char *infile;
        char *outfile;
        char **cmds;
        int nb_cmds;
        bool out_mode;
    } command_t;

    typedef struct execution_s {
        int tmpin;
        int tmpout;
        int fdin;
        int fdout;
        int pid;
        int status;
    } execution_t;

    void basic_exec(char *rd_buf, shell_t *shell);
    char *get_env_var(linked_list_t *env, char const *var);
    linked_list_t *get_env(char **env);
    char **parse_path(char *path);
    char **get_env_as_array(linked_list_t *env);
    int cd_cmd(char **cmd, linked_list_t *list, linked_list_t *penv);
    int env_cmd(char **cmd, linked_list_t *list, linked_list_t *penv);
    int setenv_cmd(char **cmd, linked_list_t *list, linked_list_t *penv);
    int unsetenv_cmd(char **cmd, linked_list_t *list, linked_list_t *penv);
    int exit_cmd(char **cmd, linked_list_t *list, linked_list_t *penv);
    int check_built_in(char **cmd, linked_list_t *env, linked_list_t *penv);
    int choose_exec(char **prgrm, linked_list_t *env);
    char *get_home(void);
    void set_list(linked_list_t *list, char **cmd);
    void disp_help_env(void);
    int cd(char *dest, linked_list_t *env, linked_list_t *penv);
    void remove_var(char *var, linked_list_t *list);
    void disp_help_setenv(void);
    int immutable_test(char *tested);
    void clean_str(char *rd_buf, size_t n);
    void set_value(linked_list_t *list, char *var, char *val);
    void swap_values(linked_list_t *list, char *var1, char *var2);
    bool ignore_nested_str(char const *str, int *i);
    bool redirection_error(char const *str);
    char *get_next_word(char const *str, int idx);
    char *rm_from_n(char *str, int idx, int offset);
    char *get_and_rm_outfile(command_t *cmd, char *str);
    char *get_and_rm_infile(command_t *cmd, char *str);
    command_t get_cmd_struct_from_str(char *str);
    void execute_line(char *cmd_line, shell_t *shell);
    void pipe_execution(command_t cmd, execution_t fds, shell_t *shell);
    void execute_smp_cmd(command_t cmd, shell_t *shell);
    bool match_str(char const *string, int idx, char *sep);

    enum nbs {IN, OUT, PIPE};

#endif