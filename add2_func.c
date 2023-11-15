#include "shell.h"
/**
 * _itoa - converts an integer to ASCII
 * @num: number
 * @bas: base
 * Reference: geeksforgeeks
 * Return: character string
 **/
char *_itoa(int num, int bas)
{
static char *dig = "0123456789abcdef";
static char buf[50];
char sig = 0;
char *ptr;
unsigned long n = (unsigned long)num;
if (num < 0)
{
n = (unsigned long)(-num);
sig = '-';
}
ptr = &buf[49];
*ptr = '\0';
do {
*--ptr = dig[n % bas];
n /= bas;
} while (n != 0);
if (sig)
*--ptr = sig;
return (ptr);
}
/**
 * _strlen - returns the length of a string
 * str - short description
 * Description: long desc
 * @str: string to be measured
 * Return: length of string
 */
int _strlen(const char *str)
{
int length = 0;
while (str[length] != '\0')
{
length++;
}
return (length + 1);
}

/**
 * printenv - prints the current environment
 * @environ: environment variable
 */
void printenv(char **environ)
{
	int i = 0;

	for (; environ[i] ; i++)
		_puts(environ[i]);
}


/**
 * search - gets the path to execute commands
 * @environ: Environment variable
 * Return: kalat_path (array of directories containing the command)
 *	or NULL on failure
 **/
char **search(char **environ)
{
	int position = 0;
	char **kalat_path;

	for (; environ[position] != NULL ; position++)
	{
		if (environ[position][0] == 'P' && environ[position][2] == 'T')
		{
			kalat_path = _which(environ[position]);
		}
	}
	return (kalat_path);
}

/**
 *_puts - prints a string
 *@str: A to be printed
 *
 *Return: void
 */
void _puts(char *str)
{
	int i;

	for (i = 0 ; str[i] != '\0' ; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
