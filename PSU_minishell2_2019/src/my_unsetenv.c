/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** my_unsetenv
*/

#include <stdlib.h>
#include "error_msg.h"
#include "minishell.h"

static char **realloc_env(char **env, int nbr)
{
    char **n_env = malloc(sizeof(char *) * (nbr + 2));
    int j = 0;

    for (int i = 0; env[i] != NULL; i++) {
        n_env[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
        for (j = 0; env[i][j] != '\0'; j++)
            n_env[i][j] = env[i][j];
        n_env[i][j] = '\0';
    }
    n_env[nbr + 1] = NULL;
    return (n_env);
}

static char **del_elem(char **env, int nbr)
{
    int i = 0;

    env[nbr] = NULL;
    for (i = nbr; env[i + 1] != NULL; i++)
        env[i] = env[i + 1];
    env[i] = NULL;
    return (env);
}

static void remove_values(minish_t *sh, char *arg)
{
    int temp = -1;

    for (int i = 0; sh->env[i] != NULL; i++)
        for (int j = 0; sh->env[i][j] != '\0'; j++) {
            if (sh->env[i][j] != arg[j])
                break;
            if (sh->env[i][j] == arg[j] && sh->env[i][j + 1] == '=')
                temp = i;
        }
    if (temp == -1)
        return;
    sh->env = del_elem(sh->env, temp);
}

void my_unsetenv(minish_t *sh)
{
    int i = 0;

    if (sh->nbr_a == 1) {
        write_error(ERROR_UNSETENV_ARGS);
        return;
    }
    for (i = 0; sh->env[i] != NULL; i++);
    sh->env = realloc_env(sh->env, i);
    for (int j = 1; j != sh->nbr_a; j++)
        remove_values(sh, sh->args[j]);
}
