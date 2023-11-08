#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c:Ther character to print
 * Return: On success 1.
 * On error, -1 is returned and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * cout - it display or prints a string
 * @str: pointer to the string to print
 *
 * Return: void
 */
void  cout(char *str)
{
	int j = 0;

	while (str[j])
	{
		_putchar(str[j]);
		j++;
	}
}
