/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** main
*/

#include <stdlib.h>
#include "error_msg.h"
#include "minishell.h"

static void free_env(minish_t *sh)
{
    for (int i = 0; sh->env[i] != NULL; i++)
        free(sh->env[i]);
    free(sh->env);
    free(sh);
}

int main(int ac, char **av, char **envp)
{
    minish_t *sh = malloc(sizeof(minish_t));

    if (sh == NULL)
        return (write_error(STR_ERROR_ALLOC));
    if (ac != 1 || av[0] == NULL)
        return (ERROR);
    copy_env(sh, envp);
    minishell(sh);
    free_env(sh);
    return (SUCCESS);
}
