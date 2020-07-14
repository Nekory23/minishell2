/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** check the command
*/

#include <stdlib.h>
#include "error_msg.h"
#include "minishell.h"

static void command(minish_t *sh, int nbr)
{
    switch (nbr) {
    case 0 :
        my_cd(sh);
        break;
    case 1 :
        my_env(sh);
        break;
    case 2 :
        my_setenv(sh);
        break;
    case 3 :
        my_unsetenv(sh);
        break;
    case 4 :
        my_exit(sh);
        break;
    }
}

static char **fill_commands(char **commands)
{
    commands[0] = "cd\0";
    commands[1] = "env\0";
    commands[2] = "setenv\0";
    commands[3] = "unsetenv\0";
    commands[4] = "exit\0";
    commands[5] = NULL;
    return (commands);
}

static void unknown_command(char *command)
{
    write_error(command);
    write_error(ERROR_COMMAND);
}

void check_command(minish_t *sh)
{
    char **commands = malloc(sizeof(char *) * 6);
    int nbr = 0;

    commands = fill_commands(commands);
    while (nbr != 5) {
        if (my_strcmp(sh->args[0], commands[nbr]))
            break;
        else
            nbr++;
    }
    free(commands);
    if (nbr == 5) {
        if (exec_bin(sh))
            return;
        if (exec_prog(sh))
            return;
        unknown_command(sh->args[0]);
        return;
    }
    command(sh, nbr);
    return;
}
