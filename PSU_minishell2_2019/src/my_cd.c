/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** my_cd
*/

#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include "error_msg.h"
#include "minishell.h"

static int count_return(char *pwd)
{
    int nbr = 1;

    for (int i = 0; pwd[i] != '\0'; i++)
        if (pwd[i] == '/')
            nbr++;
    return (nbr);
}

static void go_home(minish_t *sh)
{
    const char *pwd = "PWD";
    int temp = 0;

    for (int i = 0; sh->env[i] != NULL; i++)
        for (int j = 0; sh->env[i][j] != '\0'; j++) {
            if (sh->env[i][j] != pwd[j])
                break;
            if (sh->env[i][j] == pwd[j] && sh->env[i][j + 1] == '=')
                temp = i;
        }
    if (temp == -1)
        return;
    temp = count_return(sh->env[temp]);
    for (int i = 3; i != temp; i++)
        chdir("../");
}

static void go_there(char *dest)
{
    DIR *dir = opendir(dest);

    if (dir == NULL) {
        write_error(dest);
        write_error(ERROR_CD_NDIR);
        return;
    }
    chdir(dest);
    closedir(dir);
}

void my_cd(minish_t *sh)
{
    if (sh->nbr_a == 1)
        return (go_home(sh));
    if (sh->nbr_a > 2) {
        write_error(ERROR_CD_ARG);
        return;
    }
    go_there(sh->args[1]);
}
