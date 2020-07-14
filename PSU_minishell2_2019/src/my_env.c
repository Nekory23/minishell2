/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** my_env
*/

#include <stdlib.h>
#include "minishell.h"

void my_env(minish_t *sh)
{
    for (int i = 0; sh->env[i] != NULL; i++) {
        my_putstr(sh->env[i]);
        my_putchar('\n');
    }
}
