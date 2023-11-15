#include "shell.h"
/**
 * _env_builtin - Check if a command is an environment builtin
 * @arr_tokens: The command to check
 *
 * Return: 1 if the command is an environment builtin, 0 otherwise
 */
int _env_builtin(__attribute((unused)) char **arr_tokens)
{
int env_index;
for (env_index = 0; __environ[env_index]; env_index++)
{
write(STDOUT_FILENO, __environ[env_index],
strlen(__environ[env_index]));
write(STDOUT_FILENO, "\n", _strlen("\n"));
}
return (env_index);
}
