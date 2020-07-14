/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** my_exit
*/

#include <stdlib.h>
#include "error_msg.h"
#include "minishell.h"

static void free_all(minish_t *sh)
{
    for (int i = 0; i != sh->nbr_a; i++)
        free(sh->args[i]);
    free(sh->args);
    if (sh->nbr_i != 0) {
        for (int i = 0; i != sh->nbr_i; i++)
            free(sh->inst[i]);
        free(sh->inst);
    }
    for (int i = 0; sh->env[i] != NULL; i++)
        free(sh->env[i]);
    free(sh->env);
    free(sh);
}

static int check_nbr(char *arg, int i)
{
    for (; arg[i] != '\0'; i++) {
        if (arg[i] >= '0' && arg[i] <= '9')
            continue;
        else
            return (FALSE);
    }
    return (TRUE);
}

void my_exit(minish_t *sh)
{
    int value = 0;
    int i = 0;

    if (sh->nbr_a > 2)
        write_error(ERROR_EXIT_INV);
    if (sh->nbr_a == 1) {
        my_putstr("exit\n");
        free_all(sh);
        exit(value);
    }
    else {
        if (sh->args[1][0] == '-') {
            i++;
        }
        if (check_nbr(sh->args[1], i)) {
            value = my_atoi(sh->args[1]);
            free_all(sh);
            exit(value);
        }
    }
}
