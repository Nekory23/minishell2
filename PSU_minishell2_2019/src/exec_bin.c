/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** execute binaries
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

static char **put_command(char **paths, char *command)
{
    for (int i = 0; paths[i] != NULL; i++) {
        paths[i] = my_strcat(paths[i], "/");
        paths[i] = my_strcat(paths[i], command);
    }
    return (paths);
}

int exec_bin(minish_t *sh)
{
    char **paths = get_path(sh->env, "PATH");
    int i = 0;
    int status = 0;

    if (paths == NULL)
        return (FALSE);
    paths = put_command(paths, sh->args[0]);
    for (i = 0; paths[i] != NULL; i++)
        if (access(paths[i], F_OK) != -1)
            break;
    if (paths[i] == NULL)
        return (FALSE);
    if ((status = fork()) == 0)
        execve(paths[i], sh->args, sh->env);
    wait(&status);
    return (TRUE);
}
