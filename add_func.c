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


/**
 * str_concat - concatenate two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to the concatenated string
 */
char *str_concat(char *s1, char *s2)
{
	char *dest;
	unsigned int i, j, size;

	/* If the array is empty */
	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";
	/* Count total size */

	size = (_strlen(s1) + _strlen(s2) + 1);

	/* Allocate memory */

	dest = (char *) malloc(size * sizeof(char));

	if (dest == 0)
	{
		return (NULL);
	}

	/* Concatenate arrays */
	for (i = 0; *(s1 + i) != '\0'; i++)
		*(dest + i) = *(s1 + i);

	for (j = 0; *(s2 + j) != '\0'; j++)
	{
		*(dest + i) = *(s2 + j);
		i++;

	}
	dest[i] = '\0';
	return (dest);

}

/**
 *_calloc -allocated memoria for nmeb elemn de zise bytes
 *@nmemb: number of element in the array
 *@size: bytes for each position in the array
 *Return: pointer void
 */


void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *p;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);

	for (i = 0; i < nmemb * size; i++)
		p[i] = 0;

	return (p);

}

/**
 * _strdup - copies string and returns its pointer
 *
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
