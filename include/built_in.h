/*
** EPITECH PROJECT, 2020
** PSU_42sh
** File description:
** built_in.h
*/

#ifndef BUILT_IN_H
#define BUILT_IN_H

#include "my.h"

#include "parsing_command_line.h"

#define MAX_LEN_HISTORY (1000)

struct alias;

typedef struct {
    char **env;
    char **env_memory;
    struct alias **aliases;
    char **history;
} memory_t;

enum built_in_index {
    NONE_BI = -1,
    CD,
    ENV,
    SETENV,
    UNSETENV,
    HISTORY,
    EXIT
};

typedef struct built_ins {
    char * const name;
    bool (*fct)(char **, memory_t *);
    enum built_in_index type;
} built_ins_t;

bool exec_built_ins(char *instructions, memory_t *env_mem, command_t *next);
int is_built_in(char *instructions);

// ENV
memory_t *init_env_memory(char **env);
void free_env_mem(memory_t *env_mem);

char **path_to_path_arr(memory_t *env_mem);

char *find_var_in_env(char * const var, char **env);

bool set_env(char **av, memory_t *env_m);
bool unset_env(char **av, memory_t *env_m);
bool disp_env(UNUSED char **av, memory_t *env_m);
// !ENV

// HISTORY
char *check_fill_history(char *line, memory_t *env_mem);

bool display_history(UNUSED char **av, memory_t *env_mem);

char *check_one_mark(char *line, char **history, size_t len_history);
char *check_two_marks(char *line, char **history, size_t len_history);
// ! HISTORY

// CD
bool change_location(char **av, memory_t *env_m);
// !CD

// ALIASES
typedef struct alias {
    char *alias;
    char *substitute;
} alias_t;

alias_t **get_aliases_from_file(char **shrc_file);
alias_t **fill_aliases_from_file(char **raw_aliases, size_t nb_aliases);

bool is_alias_correct(char * const line);


// ! ALIASES

// EXIT
bool my_exit(UNUSED char **av, memory_t *env_m);
// !EXIT

#endif /* !BUILT_IN_H */
