#include "shell.h"

/**
 * execute_cmd - executes a command as a child process
 * @arr: array of arguments
 * @arg: array of parsed arguments
 * @env: environment variables
 * @sta: status of the main function
 * @cnt: command count
 *
 * Return: 1 on success
 */

int execute_cmd(char **arr, char **arg, char **env, int sta, int cnt)
{
	pid_t pid;
	int st;

	if (arg == NULL)
		return (-1);

	pid = fork();
	if (pid < 0)
	{
		perror("./hsh: ");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(arg[0], arg, env) == -1)
		{
			_error(arr[0], cnt, arg[0]);
			free(arg);
			exit(1);
		}
		exit(0);
	}
	else
	{
		if (sta == 1)
			free(arg[0]);

		free(arg);
		waitpid(pid, &st, WUNTRACED);
	}
	return (1);
}
