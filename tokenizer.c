#include "shell.h"
void handle_exit(char **kalat, char *l);
/**
 * split_str - splits str
 * @l: tokenized str
 * @env: environment var
 * Return: array of tokens
 */
char **split_str(char *l, char **env)
{
	char *tokenized_sentence, *separator = " \t\r\n\a";
	char **kalat;
	int max_kalat = 64, kotari = 0;

	if (l == NULL)
	{
		return (0);
	}
	kalat = _calloc(sizeof(char *), max_kalat);
	if (kalat == NULL)
	{
		cout("error");
		exit(EXIT_FAILURE);
	}

	tokenized_sentence = strtok(l, separator);
	while (tokenized_sentence != NULL)
	{
		kalat[kotari] = tokenized_sentence;
		kotari++;
		tokenized_sentence = strtok(NULL, separator);
	}

	if (kalat[0] == NULL)
		kalat[kotari] = "\n";

	if (_strcmp(kalat[0], "exit") == 0)
	{
		if (kalat[1] != NULL)
			handle_exit(kalat, l);

		else
			handle_exit(kalat, l);
	}
	if ((_strcmp(kalat[0], "env") == 0) && kalat[1] == NULL)
		printenv(env);

	return (kalat);

}

/**
 * _atoi - converts char to int
 * @a: char to be converted
 * Return: int
 */

int _atoi(char *a)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	while (a[i] == ' ')
	{
		i++;
	}

	if (a[i] == '-' || a[i] == '+')
	{
		sign = (a[i] == '-') ? -1 : 1;
		i++;
	}

	while (a[i] > '\0' && a[i] <= '9')
	{
		result = result * 10 + (a[i] - '0');
		i++;
	}

	return (result * sign);
}


/**
 * handle_exit - exit handler
 * @kalat:  kalat which is nice
 * @l: line in the mirrori
 * Returns: nothing
 *
 */

void handle_exit(char **kalat, char *l)
{
	int status = 0;

	if (kalat[1] != NULL)
	{
		status = _atoi(kalat[1]);
		if (status == 0 && _strcmp(kalat[1], "0") != 0)
			status = 2;
	}

	free(l);
	free(kalat);
	exit(status);
}
