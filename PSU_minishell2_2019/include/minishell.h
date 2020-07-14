/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** .h
*/

#ifndef _MINISHELL_H_
#define _MINISHELL_H_

/* STRUCT */
typedef struct minish_st
{
    char **env;
    char *buff;
    char **inst;
    char **args;
    int nbr_a;
    int mode;
    int nbr_i;
    int exit;
} minish_t;

/* COPY ENV */
void copy_env(minish_t *sh, char **envp);

/* MINISHELL */
void minishell(minish_t *sh);
char *check_buff(char *buff);
void get_the_buffers(minish_t *sh);
void get_args(minish_t *sh, char *buff);
char *clean_that(char *buff);
void check_line(minish_t *sh);
int count_args(char *buff, char sep);

/* COMMANDS */
void check_command(minish_t *sh);

/* BUILTINS */
void my_exit(minish_t *sh);
void my_env(minish_t *sh);
void my_setenv(minish_t *sh);
void my_unsetenv(minish_t *sh);
void my_cd(minish_t *sh);

/* BINARIES */
int exec_bin(minish_t *sh);
char **get_path(char **env, char const *var);

/* PROGRAMS */
int exec_prog(minish_t *sh);

/* UTIL FUNCTIONS */
void my_putchar(char c);
void my_putstr(char const *str);
int my_strlen(char *const str);
int my_strcmp(char const *str1, char const *str2);
char *my_strcat(char *dest, char const *src);
int write_error(char const *str);
int my_atoi(char *str);

/* PROMPT */
#define BL "\e[1;36m"
#define RE "\e[1;31m"
#define WHITE "\e[0;00m"
#define PROMPT RE"[~"BL" ₪ minishell ₪ "RE"~]"BL" (~‾▿‾)~⤅ "WHITE

/* MACROS */
static const int ERROR = 84;
static const int SUCCESS = 0;
static const int TRUE = 1;
static const int FALSE = 0;

#endif /* _MINISHELL_H_ */
