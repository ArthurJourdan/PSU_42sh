/*
** EPITECH PROJECT, 2020
** PSU_minishell2
** File description:
** minishell.h
*/

#ifndef MINISHELL_H
#define MINISHELL_H

#include "my.h"

#include "parsing_command_line.h"
#include "built_in.h"

#define OUT 0
#define IN 1
#define IS_WHITESPACE(x) (x == ' ' || x == '\t' || x == '\n')

typedef struct wors_to_array
{
    int wc;
    char *str;
}word_t;

bool minishell_manager(char **env);

// COMMAND
char *command_match(char **path_arr, char * const is_command);

bool check_direct_exec(char *command);

void set_pipes(int pipefd[2][2], command_t *command, int fst_or_sec);
void set_redirections(command_t *command);

bool command_exec(char *line, memory_t *env_mem);

bool check_command(command_t *pre_command, memory_t *env_mem);

bool exec_error_msg(char *comd);
bool after_exec_error_msg(char *comd);
bool understand_status(int status);

// !COMMAND
//GLOBBING

char *my_strdup(char const *src);
char *my_strcpy1(char *dest , char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char **my_str_to_word_array(char *str);
word_t countwords(char *str);
char *is_wildcard(char *cmd);
int *check_wildcard(char **newcmd);
//!GLOBBING

#endif /* !MINISHELL_H */
