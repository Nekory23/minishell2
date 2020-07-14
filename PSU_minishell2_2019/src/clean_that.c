/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** clean the buffer
*/

#include <stdlib.h>
#include "minishell.h"

static int find_char(char *buffer, int i)
{
    int nb = i;

    for (; buffer[i] != '\0'; i++) {
        if (buffer[i] != ' ' && buffer[i] != '\t') {
            nb = i;
            break;
        }
    }
    return (nb);
}

static char *clean_buff(char *bf)
{
    char *str = malloc(sizeof(char) * (my_strlen(bf) + 1));

    for (int i = find_char(bf, 0), j = 0; bf[i] != '\0'; i++) {
        if (bf[i] == ' ' && (bf[i + 1] == ' ' || bf[i + 1] == '\t')) {
            str[j] = ' ';
            j++;
            i = find_char(bf, i);
            i--;
        }
        else if (bf[i] == '\t' && (bf[i + 1] == ' ' || bf[i + 1] == '\t')) {
            str[j] = ' ';
            j++;
            i = find_char(bf, i);
            i--;
        } else {
            str[j] = bf[i];
            j++;
        }
    }
    return (str);
}

char *clean_that(char *buff)
{
    int i = 0;

    buff = clean_buff(buff);
    for (i = 0; buff[i] != '\0'; i++)
        if (buff[i] == '\n') {
            buff[i] = '\0';
            break;
        }
    while (buff[i - 1] == ' ' || buff[i - 1] == '\t') {
        buff[i - 1] = '\0';
        i--;
    }
    buff[i] = '\0';
    return (buff);
}
