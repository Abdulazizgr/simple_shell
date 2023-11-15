#include "shell.h"
/**
 * prompt - prints prompt
 * Return: void
 */
void prompt(void)
{
char *buf = getcwd(NULL, 0);
if (isatty(STDIN_FILENO))
cout("#zizu$ ");
free(buf);
}
