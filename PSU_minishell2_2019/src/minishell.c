/*
** EPITECH PROJECT, 2020
** minishell.c
** File description:
** run the minishell
*/

#include <stdlib.h>
#include <stdio.h>
#include "minishell.h"

static void gest_eof(minish_t *sh)
{
    my_putstr("exit\n");
    free(sh->buff);
    return;
}

void minishell(minish_t *sh)
{
    long unsigned size = 10;

    sh->buff = malloc(sizeof(char) * size);
    my_putstr(PROMPT);
    if (getline(&sh->buff, &size, stdin) == EOF)
        return (gest_eof(sh));
    if (check_buff(sh->buff) == NULL)
        minishell(sh);
    check_line(sh);
    minishell(sh);
}
