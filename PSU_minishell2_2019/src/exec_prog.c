/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** execute programs
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include "error_msg.h"
#include "minishell.h"

static int check_path(char *arg, char **env)
{
    char **path = get_path(env, "PATH");

    if (path == NULL)
        return (FALSE);
    for (int i = 0; path[i] != NULL; i++)
        if (my_strcmp(path[i], arg))
            return (TRUE);
    return (FALSE);
}

static char *get_name(char *arg)
{
    char *name = malloc(sizeof(char) * (my_strlen(arg) + 1));

    for (int i = 0, j = 2; arg[j] != '\0'; i++, j++)
        name[i] = arg[j];
    return (name);
}

static int check_if_dir(minish_t *sh)
{
    char *name = get_name(sh->args[0]);
    struct stat st;

    if (sh->args[0][0] != '.') {
        if (S_ISDIR(st.st_mode) || check_path(sh->args[0], sh->env)) {
            write_error(sh->args[0]);
            write_error(PERMISSION_DENIED);
            return (TRUE);
        }
        return (FALSE);
    }
    stat(name, &st);
    if (S_ISDIR(st.st_mode)) {
        write_error(name);
        write_error(PERMISSION_DENIED);
        free(name);
        return (TRUE);
    }
    free(name);
    return (FALSE);
}

int exec_prog(minish_t *sh)
{
    int pid = 0;
    int status = 0;

    if (check_if_dir(sh))
        return (TRUE);
    if (access(sh->args[0], F_OK) == -1)
        return (FALSE);
    if ((pid = fork()) == 0)
        execve(sh->args[0], sh->args, sh->env);
    wait(&status);
    return (TRUE);
}
