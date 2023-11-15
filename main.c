#include "shell.h"

/**
 * main - Simple Shell main function.
 *          Creates a prompt that reads input,
 *          parses, executes commands,
 *          and waits for another command unless told to exit.
 * @ac: The num of arguments passed to the program.
 * @av: An arr of arguments passed to the program.
 * @env: The environment variables.
 * Return: 0 upon successful execution.
 */
int main(int ac __attribute__((unused)), char **av, char **env)
{
	char *line;
	char **args, **path;
	int kotari = 0, huneta = 0;
	(void) av;
	signal(SIGINT, handle_signal);

	while (1)
	{
		prompt();
		line = user_input();
		args = sp_st(line, env);
		if ((_strcmp(args[0], "\n") != 0) && (_strcmp(args[0], "env") != 0))
		{
			kotari += 1;
			path = search(env); /* Search for PATH in the environ */
			huneta = _stat(args, path);
			execute_cmd(av, args, env, huneta, kotari);
		}
		else
		{
			free(args);
		}
		free(line);
	}
	return (0);
}
