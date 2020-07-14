/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** check the line
*/

#include <stdlib.h>
#include "minishell.h"

static void check_semi(minish_t *sh)
{
    for (int i = 0; sh->buff[i] != '\0'; i++)
        if (sh->buff[i] == ';')
            sh->mode = 1;
}

static void free_args(char **args)
{
    for (int i = 0; args[i] != NULL; i++)
        free(args[i]);
    free(args);
}

void check_line(minish_t *sh)
{
    sh->mode = 0;
    sh->nbr_a = 0;
    sh->nbr_i = 0;
    sh->buff = clean_that(sh->buff);
    check_semi(sh);
    if (sh->mode == 0) {
        get_args(sh, sh->buff);
        check_command(sh);
        free_args(sh->args);
    }
    if (sh->mode == 1) {
        get_the_buffers(sh);
        for (int i = 0; i != sh->nbr_i; i++) {
            get_args(sh, sh->inst[i]);
            check_command(sh);
            free_args(sh->args);
        }
    }
}
