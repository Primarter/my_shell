/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** execute_line.c
*/

#include "basic.h"

void execute_line(char *cmd_line, shell_t *shell)
{
    char **smp_cmds = my_sep_array(cmd_line, ';');
    size_t len = array_len(smp_cmds);
    command_t cmd = {};

    if (!smp_cmds)
        return;
    for (size_t i = 0; i < len; i++) {
        cmd = get_cmd_struct_from_str(smp_cmds[i]);
        if (!cmd.cmds) {
            write(2, "line command error\n", 19);
            return;
        }
        execute_smp_cmd(cmd, shell);
    }
    if (!smp_cmds)
        shell->lret = 0;
}

void pipe_execution(command_t cmd, execution_t fds, shell_t *shell)
{
    mode_t om = cmd.out_mode ? 01 | O_APPEND | O_CREAT : 01 | O_CREAT;
    int fdpipe[2];

    for (int i = 0; i < cmd.nb_cmds; i++) {
        dup2(fds.fdin, 0);
        close(fds.fdin);
        if (i == cmd.nb_cmds - 1) {
            if(cmd.outfile)
                fds.fdout = open(cmd.outfile, om, 0644);
            else
                fds.fdout = dup(fds.tmpout);
        } else {
            pipe(fdpipe);
            fds.fdout = fdpipe[1];
            fds.fdin = fdpipe[0];
        }
        dup2(fds.fdout, 1);
        close(fds.fdout);
        basic_exec(cmd.cmds[i], shell);
    }
}

void wait_for_all(shell_t *shell)
{
    int sig_nb = 0;
    int status = 0;
    int pid = 0;

    pid = wait(&(status));
    if (pid == -1) {
        shell->lret = 84;
        return;
    }
    if (WIFSIGNALED(status)) {
        sig_nb = WTERMSIG(status);
        for (int i = 0; sigtab[i].sig; i++)
            sig_nb == sigtab[i].sig ? my_printf("%s", sigtab[i].mess) : sig_nb;
        if (WCOREDUMP(status))
            my_printf(" (core dumped)");
        write(1, "\n", 1);
    }
    shell->lret = status;
}

void execute_smp_cmd(command_t cmd, shell_t *shell)
{
    execution_t fds = {
        .tmpin = dup(0),
        .tmpout = dup(1),
        .fdin = 0,
        .fdout = 1,
        .pid = -1,
        .status = -1,
    };

    if (cmd.infile) {
        fds.fdin = open(cmd.infile, O_RDONLY);
    } else
        fds.fdin = dup(fds.tmpin);
    pipe_execution(cmd, fds, shell);
    dup2(fds.tmpin, 0);
    dup2(fds.tmpout, 1);
    close(fds.tmpin);
    close(fds.tmpout);
    wait_for_all(shell);
}