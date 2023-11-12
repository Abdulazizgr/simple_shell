#include "shell.h"
/**
 * _strcmp - compares two strings
 * @str1: first string
 * @str2: second string
 * Return: integer
 */
int _strcmp(char *str1, char *str2)
{
int s;
s = 0;
while (str1[s] != '\0' && str2[s] != '\0')
{
if (str1[s] != str2[s])
return (str1[s] - str2[s]);
s++;
}
return (0);
}
/**
 * printErr - prints the error output of a file
 * @arg: name of program
 * @cnt: number of prompt
 * @cmd: command to be put in
 * Return: 0 on success
 */
int *printErr(char *arg, int cnt, char *cmd)
{
char *num;
num = _itoa(cnt, 10);
write(2, arg, _strlen(arg));
write(2, ": ", 2);
write(2, num, _strlen(num));
write(2, ": ", 2);
write(2, cmd, _strlen(cmd));
perror(" ");
return (0);
}
