#include "shell.h"
/**
 * user_input - reads input from standard input and returns it as string
 * Return: a string containing the input or null on error
 */
char *user_input(void)
{
	char *inputword = NULL;
	ssize_t bytre;
	size_t busize;
	int n;

	busize = 0;
	bytre = getline(&inputword, &busize, stdin);
	if (!inputword)
	{
		perror("Error allocating memory for buffer");
		return (0);
	}
	if (bytre == 1)
	{
		free(inputword);
		return (NULL);
	}
	else if (bytre == EOF)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(inputword);
		exit(0);
	}
	else
	{
		for (n = 0; inputword[n] == ' ' && inputword[n + 1] == ' '; n++)
			;
		if (!inputword[n] && inputword[n + 1] == '\n')
		{
			free(inputword);
			return (NULL);
		}
	}

	return (inputword);
}

