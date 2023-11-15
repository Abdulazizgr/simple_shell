#include "shell.h"
void han_exit(char **tok, char *ln);
/**
 * sp_st - splits str
 * @ln: tokenized str
 * @env: environment var
 * Return: array of tokens
 */
char **sp_st(char *ln, char **env)
{
	char *tok, *sep = " \t\r\n\a";
	char **arr;
	int max_arr = 64, cnt = 0;

	if (ln == NULL)
	{
		return (0);
	}
	arr = _calloc(sizeof(char *), max_arr);
	if (arr == NULL)
	{
		cout("error");
		exit(EXIT_FAILURE);
	}

	tok = strtok(ln, sep);
	while (tok != NULL)
	{
		arr[cnt] = tok;
		cnt++;
		tok = strtok(NULL, sep);
	}

	if (arr[0] == NULL)
		arr[cnt] = "\n";

	if (_strcmp(arr[0], "exit") == 0)
	{
		if (arr[1] != NULL)
			han_exit(arr, ln);

		else
			han_exit(arr, ln);
	}
	if ((_strcmp(arr[0], "env") == 0) && arr[1] == NULL)
		printenv(env);

	return (arr);
}

/**
 * _charint - converts char to int
 * @str: char to be converted
 * Return: int
 */
int _charint(char *str)
{
	int res = 0;
	int sign = 1;
	int i = 0;

	while (str[i] == ' ')
	{
		i++;
	}

	if (str[i] == '-' || str[i] == '+')
	{
		sign = (str[i] == '-') ? -1 : 1;
		i++;
	}

	while (str[i] > '\0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}

	return (res * sign);
}

/**
 * han_exit - exit handler
 * @tok:  array of tokens
 * @ln: line of input
 * Returns: nothing
 */
void han_exit(char **tok, char *ln)
{
	int stat = 0;

	if (tok[1] != NULL)
	{
		stat = _charint(tok[1]);
		if (stat == 0 && _strcmp(tok[1], "0") != 0)
			stat = 2;
	}

	free(ln);
	free(tok);
	exit(stat);
}
