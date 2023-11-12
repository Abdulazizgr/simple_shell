#include "shell.h"
/**
 * _env_builtin - print environ
 * @arr_tokens: cmd array for tokens
 * Return : 0 for failure 1 for sucess
 */
int _env_builtin(__attribute((unused)) char **arr_tokens)
{
int enviroment_index;
for (enviroment_index = 0; __environ[enviroment_index]; enviroment_index++)
{
write(STDOUT_FILENO, __environ[enviroment_index],
strlen(__environ[enviroment_index]));
write(STDOUT_FILENO, "\n", strlen("\n"));
}
return (enviroment_index);
}
