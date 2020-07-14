/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** error messages
*/

#ifndef _ERROR_MSG_H_
#define _ERROR_MSG_H_

/* ERROR ALLOC */
static const char STR_ERROR_ALLOC[] = "Alloctation failed\n";

/* PERMISSION DENIED */
static const char PERMISSION_DENIED[] = ": Permission denied.\n";

/* COMMAND NOT FOUND*/
static const char ERROR_COMMAND[] = ": Command not found.\n";

/* EXIT */
static const char ERROR_EXIT_INV[] = "exit: Expression Syntax.\n";
static const char ERROR_EXIT_NBR[] = "exit: Badly formed number.\n";

/* SETENV */
static const char ERROR_SETENV_VAR[] = "setenv: Variable name must ";
static const char ERROR_SETENV_VAR2[] = "begin with a letter.\n";
static const char ERROR_SETENV_ARGS[] = "setenv: Too many arguments.\n";
static const char ERROR_SETENV_ALPH[] = "setenv: Variable name must ";
static const char ERROR_SETENV_ALPH2[] = "contain alphanumeric characters.\n";

/* CD */
static const char ERROR_CD_ARG[] = "cd: Too many arguments.\n";
static const char ERROR_CD_NDIR[] = ": No such file or directory.\n";
static const char ERROR_CD_FILE[] = ": Not a directory.\n";

/* UNSETENV */
static const char ERROR_UNSETENV_ARGS[] = "unsetenv: Too few arguments.\n";

#endif /*_ERROR_MSG_H_*/
