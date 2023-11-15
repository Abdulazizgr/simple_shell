#include "shell.h"
/**
 * _itoa - converts an integer to ASCII
 * @n: number
 * @b: base
 * Return: character string
 **/
char *_itoa(int n, int b)
{
static char *d = "0123456789abcdef";
static char buf[50];
char s = 0;
char *p;
unsigned long m = (unsigned long)n;
if (n < 0)
{
m = (unsigned long)(-n);
s = '-';
}
p = &buf[49];
*p = '\0';
do {
*--p = d[m % b];
m /= b;
} while (m != 0);
if (s)
*--p = s;
return (p);
}
/**
 * _strlen - returns the length of a string
 * @s: string to be measured
 * Return: length of string
 */
int _strlen(const char *s)
{
int l = 0;
while (s[l] != '\0')
{
l++;
}
return (l + 1);
}
/**
 * printenv - prints the current environment
 * @e: environment variable
 */
void printenv(char **e)
{
int i = 0;
for (; e[i]; i++)
{
_print(e[i]);
}
}
/**
 * search - gets the path to execute commands
 * @e: environment variable
 * Return: path (array of directory containing the command) or NULL on failure
 **/
char **search(char **e)
{
int p = 0;
char **pa;
for (; e[p] != NULL; p++)
{
if (e[p][0] == 'P' && e[p][2] == 'T')
{
pa = _finpath(e[p]);
}
}
return (pa);
}
/**
 * _print - prints a string
 * @s: string to be printed
 * Return: void
 */
void _print(char *s)
{
int i;
for (i = 0; s[i] != '\0'; i++)
{
_putchar(s[i]);
}
_putchar('\n');
}
