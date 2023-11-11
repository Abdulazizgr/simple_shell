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

 /***for tokenizer.c***/
void handle_exit(char **kalat, char *l);
char **split_str(char *l, char **env)
int _atoi(char *a)
void handle_exit(char **kalat, char *l)

/***for handler_err.c***/
void handle_signal(int sign)
int _stat(char **cmd, char **menged)
int *_error(char *argv, int count, char *args)

#endif
