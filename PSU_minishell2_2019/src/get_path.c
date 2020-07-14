/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** get the paths for the binaries
*/

#include <stdlib.h>
#include "minishell.h"

static int remove_value(char *path)
{
    int i = 0;

    for (i = 0; path[i] != '='; i++);
    i++;
    return (i);
}

static char **separate_paths(char *path)
{
    int nbr = count_args(path, ':');
    char **sep = malloc(sizeof(char *) * (nbr + 1));
    int i = remove_value(path);

    for (int j = 0; j != nbr; j++)
        sep[j] = malloc(sizeof(char) * (my_strlen(path) + 1));
    for (int j = 0, z = 0; path[i] != 0; i++, z++) {
        if (path[i] == ':') {
            sep[j][z] = '\0';
            i++;
            j++;
            z = 0;
        }
        if (path[i + 1] == '\0') {
            sep[j][z] = path[i];
            sep[j][z + 1] = '\0';
        }
        sep[j][z] = path[i];
    }
    sep[nbr] = NULL;
    return (sep);
}

char **get_path(char **env, char const *var)
{
    int temp = -1;
    char **paths;

    for (int i = 0; env[i] != NULL; i++)
        for (int j = 0; env[i][j] != '\0'; j++) {
            if (env[i][j] != var[j])
                break;
            if (env[i][j] == var[j] && env[i][j + 1] == '=')
                temp = i;
        }
    if (temp == -1)
        return (NULL);
    paths = separate_paths(env[temp]);
    return (paths);
}
