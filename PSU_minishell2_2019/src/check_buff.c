/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** checks if the buffer is null
*/

#include <stdlib.h>
#include "minishell.h"

char *check_buff(char *buff)
{
    int nbr = 0;

    for (int i = 0; buff[i] != '\n'; i++)
        if (buff[i] == ' ' || buff[i] == '\t')
            nbr++;
    if (nbr == (my_strlen(buff) - 1))
        return (NULL);
    return (buff);
}
