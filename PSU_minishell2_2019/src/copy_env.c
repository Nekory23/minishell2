/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** copy the environment
*/

#include "minishell.h"
#include <stdlib.h>

void copy_env(minish_t *sh, char **envp)
{
    int i = 0;
    int z = 0;

    while (envp[i])
        i++;
    sh->env = malloc(sizeof(char *) * (i + 2));
    for (int j = 0; j != i; j++) {
        sh->env[j] = malloc(sizeof(char) * (my_strlen(envp[j]) + 1));
        for (z = 0; envp[j][z] != '\0'; z++)
            sh->env[j][z] = envp[j][z];
        sh->env[j][z] = '\0';
    }
    sh->env[i] = NULL;
}
