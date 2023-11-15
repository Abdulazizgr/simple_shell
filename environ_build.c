#include "shell.h"
/**
 * _env_builtin - print environ
 * @arr_tokens: cmd array for tokens
 * Return : 0 for failure 1 for sucess
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
