/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** my_setenv
*/

#include <stdlib.h>
#include "error_msg.h"
#include "minishell.h"

static int check_alpha(char *ar)
{
    int i = 0;
    int len = my_strlen(ar);

    for (i = 0; ar[i] != '\0'; i++) {
        if ((ar[i] >= '0' && ar[i] <= '9') || (ar[i] >= 'A' && ar[i] <= 'Z'))
            continue;
        if ((ar[i] >= 'a' && ar[i] <= 'z') || ar[i] == '_')
            continue;
        else
            break;
    }
    if (i == len)
        return (FALSE);
    write_error(ERROR_SETENV_ALPH);
    write_error(ERROR_SETENV_ALPH2);
    return (TRUE);    
}

static int check_args(char **args)
{
    int ok = 0;

    if (args[1][0] >= 'a' && args[1][0] <= 'z')
        ok++;
    else if ((args[1][0] >= 'A' && args[1][0] <= 'Z') || args[1][0] == '_')
        ok++;
    if (ok == 1) {
        if (check_alpha(args[1]))
            return (TRUE);
        else
            return (FALSE);
    }
    write_error(ERROR_SETENV_VAR);
    write_error(ERROR_SETENV_VAR2);
    return (TRUE);
}

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

static void change_value(minish_t *sh, int nbr)
{
    int temp = -1;

    for (int i = 0; sh->env[i] != NULL; i++)
        for (int j = 0; sh->env[i][j] != '\0'; j++) {
            if (sh->env[i][j] != sh->args[1][j])
                break;
            if (sh->env[i][j] == sh->args[1][j] && sh->env[i][j + 1] == '=')
                temp = i;
        }
    if (temp == -1) {
        if (sh->nbr_a >= 2) {
            sh->env[nbr] = my_strcat(sh->args[1], "=");
            if (sh->args[2] != NULL)
                sh->env[nbr] = my_strcat(sh->env[nbr], sh->args[2]);
        }
    }
    sh->env[temp] = my_strcat(sh->args[1], "=");
    if (sh->args[2] != NULL)
        sh->env[temp] = my_strcat(sh->env[temp], sh->args[2]);
}

void my_setenv(minish_t *sh)
{
    int i = 0;

    if (sh->nbr_a > 4) {
        write_error(ERROR_SETENV_ARGS);
        return;
    }
    if (sh->args[1] == NULL) {
        my_env(sh);
        return;
    }
    if (check_args(sh->args))
        return;
    for (i = 0; sh->env[i] != NULL; i++);
    sh->env = realloc_env(sh->env, i);
    change_value(sh, i);
}
