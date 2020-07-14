/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** get the args
*/

#include <stdlib.h>
#include "minishell.h"

int count_args(char *buff, char sep)
{
    int nbr = 1;

    for (int i = 0; buff[i] != '\0'; i++)
        if (buff[i] == sep)
            nbr++;
    return (nbr);
}

void get_args(minish_t *sh, char *buff)
{
    int nbr = count_args(buff, ' ');

    sh->args = malloc(sizeof(char *) * (nbr + 1));
    for (int i = 0; i != nbr; i++)
        sh->args[i] = malloc(sizeof(char) * (my_strlen(buff) + 1));
    for (int i = 0, j = 0, z = 0; buff[i] != '\0'; i++, z++) {
        if (buff[i] == ' ') {
            sh->args[j][z] = '\0';
            i++;
            j++;
            z = 0;
        }
        if (buff[i + 1] == '\0') {
            sh->args[j][z] = buff[i];
            sh->args[j][z + 1] = '\0';
            break;
        }
        sh->args[j][z] = buff[i];
    }
    sh->args[nbr] = NULL;
    sh->nbr_a = nbr;
}
