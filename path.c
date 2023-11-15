#include "shell.h"

/**
 * _finpath - short description
 * @fpt: the command that is being passed to it
 *
 * Return: an array of directories containing the command or NULL on failure
 */
char **_finpath(char *fpt)
{
	int siz = 64;
	int i = 0;
	char *cpy = NULL;
	char *del = ":=";

	char **drs = _calloc(sizeof(char *), siz);
	char *tok = NULL;

	if (fpt == NULL)
	{
		free(fpt);
		return (NULL);
	}
	if (drs == NULL)
	{
		free(fpt);
		perror("Error allocating memory");
		return (NULL);
	}
	cpy = _strdup(fpt); /* Copy the fpt string */
	tok = strtok(cpy, del); /* Split the string by the delimiter */

	while (tok != NULL)
	{
		drs[i] = tok;
		i++;
		tok = strtok(NULL, del);
	}
	return (drs);
}
