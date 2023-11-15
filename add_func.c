#include "shell.h"
/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: integer
 */
int _strcmp(char *s1, char *s2)
{
int i;
i = 0;
while (s1[i] != '\0' && s2[i] != '\0')
{
if (s1[i] != s2[i])
return (s1[i] - s2[i]);
i++;
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
char *n;
n = _itoa(cnt, 10);
write(2, arg, _strlen(arg));
write(2, ": ", 2);
write(2, n, _strlen(n));
write(2, ": ", 2);
write(2, cmd, _strlen(cmd));
perror(" ");
return (0);
}
/**
 * str_concat - concatenate two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to the concatenated string
 */
char *str_concat(char *s1, char *s2)
{
char *d;
unsigned int i, j, size;
/* If the array is empty */
if (s1 == NULL)
s1 = "";
if (s2 == NULL)
s2 = "";
/* Count total size */
size = (_strlen(s1) + _strlen(s2) + 1);
/* Allocate memory */
d = (char *) malloc(size *sizeof(char));
if (d == 0)
{
return (NULL);
}
/* Concatenate arrays */
for (i = 0; *(s1 + i) != '\0'; i++)
*(d + i) = *(s1 + i);
for (j = 0; *(s2 + j) != '\0'; j++)
{
*(d + i) = *(s2 + j);
i++;
}
d[i] = '\0';
return (d);
}
/**
 * _calloc - allocate memory for nmemb elements of size bytes
 * @n: number of elements in the array
 * @s: bytes for each position in the array
 * Return: void pointer
 */
void *_calloc(unsigned int n, unsigned int s)
{
char *p;
unsigned int i;
if (n == 0 || s == 0)
return (NULL);
p = malloc(n *s);
if (p == NULL)
return (NULL);
for (i = 0; i < n *s; i++)
p[i] = 0;
return (p);
}
/**
 * _strdup - copies string and returns its pointer
 * @str: string to be copied
 * Return: String
 */
char *_strdup(char *str)
{
char *dup;
unsigned int i, count;
i = 0;
count = 0;
if (str == NULL)
return (NULL);
while (str[i] != '\0')
{
i++;
count++;
}
count++;
dup = malloc(sizeof(char) * count);
if (dup == NULL)
return (NULL);
for (i = 0; i < sizeof(char) * count; i++)
dup[i] = str[i];
return (dup);
}
