#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

int execute_cmd(char **arr, char **arg, char **env, int sta, int cnt);
void prompt(void);
int _putchar(char c);
void  cout(char *str);
char *user_input(void);
int *printErr(char *arg, int cnt, char *cmd);
char *_itoa(int num, int bas);
int _strlen(const char *str);
int _strcmp(char *str1, char *str2);
char *str_concat(char *s1, char *s2);
void *_calloc(unsigned int nmemb, unsigned int size);
void printenv(char **environ);
char **search(char **environ);
void _puts(char *str);
char **_which(char *fpath);
char *_strdup(char *str);

 /***for tokenizer.c***/
void handle_exit(char **kalat, char *l);
char **sp_st(char *l, char **env);
int _atoi(char *a);
void handle_exit(char **kalat, char *l);

/***for handler_err.c***/
void handle_signal(int sign);
int _stat(char **cmd, char **menged);
int *_error(char *argv, int count, char *args);


/***environ_build.c***/
int _env_builtin(__attribute((unused)) char **arr_tokens);


char *_getenv(const char *na);
void create_envar(char **env_var, unsigned int envar_len, const char *na, const char *val);
int _env_set_exists(char *env_var, unsigned int envar_len, const char *na, int overwrite);
int env_does_not_exists(char *env_var, unsigned int envar_len, unsigned int env_length);
int _setenv(const char *na, const char *val, int overwrite);

/***print_environ.c***/
int _print_env(void);

#endif
