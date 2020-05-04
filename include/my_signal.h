/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_signal.h
*/

typedef struct my_sig_tab_s {
    int sig;
    char *mess;
} my_sig_tab_t;

static const my_sig_tab_t sigtab[27] =
{
    {1, "Hangup (SIGHUP)"},
    {2, "(SIGINT)"},
    {3, "Quit (SIGQUIT)"},
    {4, "Illegal instruction (SIGILL)"},
    {5, "Trace trap (SIGTRAP)"},
    {6, "IOT trap (SIGIOT)"},
    {7, "Bus error (SIGBUS)"},
    {8, "Floating exception"},
    {9, "Kill (SIGKILL)"},
    {10, "User defined signal 1 (SIGUSR1)"},
    {11, "Segmentation fault"},
    {12, "User defined signal 2 (SIGUSR2)"},
    {13, "Broken pipe or no reader pipe (SIGPIPE)"},
    {14, "Alarm clock (SIGALRM)"},
    {15, "Program terminated (SIGTERM)"},
    {16, "Stack fault (SIGSTKFLT)"},
    {17, "Child process stopped or exited, changed (SIGCHLD)"},
    {19, "Stop (SIGSTOP)"},
    {20, "Terminal stop (SIGTSTP)"},
    {23, "Urgent condition on socket (SIGURG)"},
    {24, "CPU limit exceeded (SIGXCPU)"},
    {25, "File size limit exceeded (SIGXFSZ)"},
    {26, "Virtual alarm clock (SIGVTALRM)"},
    {27, "Profiling alarm clock (SIGPROF)"},
    {29, "I/O now possible (SIGIO)"},
    {30, "Power failure restart (SIGPWR)"},
    {0, NULL}
};