/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** get all the command buffers
*/

#include <stdlib.h>
#include "minishell.h"

static int count_buffs(char *buff, char sep)
{
    int nbr = 1;

    for (int i = 0; buff[i] != '\0'; i++)
        if (buff[i] == sep)
            nbr++;
    return (nbr);
}

void get_the_buffers(minish_t *sh)
{
    int j = 0;
    int z = 0;

    sh->nbr_i = count_buffs(sh->buff, ';');
    sh->inst = malloc(sizeof(char *) * (sh->nbr_i + 2));
    for (int i = 0; i != sh->nbr_i; i++)
        sh->inst[i] = malloc(sizeof(char) * (my_strlen(sh->buff) + 1));
    for (int i = 0; sh->buff[i] != '\0'; i++, z++) {
        if (sh->buff[i] == ';') {
            sh->inst[j][z] = '\0';
            i++;
            j++;
            z = 0;
        }
        sh->inst[j][z] = sh->buff[i];
    }
    sh->inst[j][z] = '\0';
    sh->inst[sh->nbr_i + 1] = NULL;
    for (int i = 0; i != sh->nbr_i; i++)
        sh->inst[i] = clean_that(sh->inst[i]);
}
