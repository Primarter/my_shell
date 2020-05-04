/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** env.c
*/

#include "my.h"
#include "my_list.h"
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

void check_defaults(linked_list_t *env);

void clean_str(char *rd_buf, size_t n);

void set_value(linked_list_t *list, char *var, char *val);

char *get_env_var(linked_list_t *env, char const *var);

void parse_env(char **env, linked_list_t *env_cpy);

char *get_home(void)
{
    DIR *homep = opendir("/home");
    struct dirent *home_dir = homep ? readdir(homep) : NULL;
    char *env_home = NULL;

    if (!homep)
        return (my_strdup("/"));
    if (!home_dir)
        return (my_strdup("/home"));
    env_home = my_strdup(home_dir->d_name);
    closedir(homep);
    return (env_home);
}

char *get_user(void)
{
    DIR *homep = opendir("/home");
    struct dirent *home_dir = homep ? readdir(homep) : NULL;
    char *env_usr = NULL;

    if (!homep || !home_dir)
        return (my_strdup("root"));
    env_usr = my_strdup(home_dir->d_name);
    closedir(homep);
    return (env_usr);
}

char *get_grp(void)
{
    DIR *homep = opendir("/home");
    struct dirent *home_dir = homep ? readdir(homep) : NULL;
    char *env_grp = NULL;

    if (!homep || !home_dir)
        return (my_strdup("root"));
    env_grp = my_strdup(home_dir->d_name);
    closedir(homep);
    return (env_grp);
}

linked_list_t *get_default_env(void)
{
    linked_list_t *new_env = init_list();
    char *cwd = malloc(sizeof(char) * 32778);
    char *pa = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/bin:/sbin";

    clean_str(cwd, 32778);
    getcwd(cwd, 32778);
    new_env->first->value = cwd;
    new_env->first->var = my_strdup("PWD");
    push_first(new_env, my_strdup("OLDPWD"), my_strdup(cwd));
    push_first(new_env, my_strdup("HOME"), my_strdup("/home"));
    push_first(new_env, my_strdup("PATH"), pa);
    push_first(new_env, my_strdup("GROUP"), get_grp());
    push_first(new_env, my_strdup("USER"), get_user());
    return (new_env);
}

linked_list_t *get_env(char **env)
{
    linked_list_t *env_cpy = init_list();
    char *cwd = malloc(sizeof(char) * 32778);

    if (!env[0] || !env) {
        free(cwd);
        return (get_default_env());
    }
    clean_str(cwd, 32778);
    getcwd(cwd, 32778);
    parse_env(env, env_cpy);
    if (!get_env_var(env_cpy, "PWD"))
        set_value(env_cpy, "PWD", cwd);
    else
        free(cwd);
    set_value(env_cpy, "OLDPWD", get_env_var(env_cpy, "PWD"));
    return (env_cpy);
}