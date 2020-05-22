/*
** EPITECH PROJECT, 2020
** PSU_minishell2
** File description:
** parsing_errors.c
*/

#include "my.h"

#include "minishell.h"
#include "parsing_command_line.h"

bool is_separator(command_t *tmp)
{
    if (!tmp)
        return false;
    if (tmp->type == COMMAND || tmp->type == MY_FILE || tmp->type == BUILT_IN)
        return false;
    if (tmp->type == SEMICOLON || tmp->type == BACKTIC)
        return false;
    return true;
}

bool is_separator_beg_end(command_t *tmp)
{
    if (!tmp)
        return false;
    if (tmp->type == COMMAND || tmp->type == MY_FILE || tmp->type == BUILT_IN)
        return false;
    if (tmp->type == SEMICOLON || tmp->type == BACKTIC)
        return false;
    return true;
}

bool pipe_with_file(command_t *tmp)
{
    if (!tmp)
        return false;
    if (tmp->type == SIMPLE_I) {
        if (tmp->next && tmp->next->type == MY_FILE)
            return false;
        if (tmp->prev && tmp->prev->type == MY_FILE)
            return false;
        if (tmp->next && tmp->next->next && tmp->next->next->type >= S_REDIRECT
&& tmp->next->next->type <= W_REDIRECT_IN)
            return false;
    }
    return true;
}

bool missing_file(command_t *tmp)
{
    if (!tmp)
        return false;
    if (tmp->type >= S_REDIRECT && tmp->type <= W_REDIRECT_IN) {
        if (!tmp->next)
            return true;
        if (tmp->next->type >= S_REDIRECT && tmp->next->type <= W_REDIRECT_IN) {
            return false;
        }
    }
    return true;
}
