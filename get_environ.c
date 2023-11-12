#include "main.h"
/**
 * _getenv - short description
 * Description: long description
 * @na: argument_1 description
 * Return: return description
 */
char *_getenv(const char *na)
{
	unsigned int env_index, envar_len;
	char *env_var;
	char *env_var_cpy;

	for (env_index = 0; __environ[env_index]; env_index++)
	{
		if (strncmp(__environ[env_index], na, strlen(na)) == 0)
		{
			envar_len = strlen(__environ[env_index]) - (strlen(na));
			env_var = malloc(sizeof(char) * envar_len);
			if (env_var == NULL)
			{
				perror("_getenv() Error: env_var malloc failed");
				return (NULL);
			}
			malloc_char(&env_var_cpy, strlen(__environ[env_index]) + 1,
					"_getenv() malloc error");
			strcpy(env_var_cpy, __environ[env_index]);
			strncpy(env_var, env_var_cpy += (strlen(na) + 1), envar_len);
			free(env_var_cpy -= (strlen(na) + 1));
			return (env_var);
		}
	}
	return (NULL);
}


/*** set env***/

/**
 * create_envar - short description
 *
 * Description: long description
 *
 * @env_var: argument_1 description
 * @envar_len: argument_2 description
 * @na: na string
 * @val: val str
 *
 * Return: return description
 */
void create_envar(char **env_var, unsigned int envar_len, const char *na,
		const char *val)
{
	*env_var = malloc_char(env_var, envar_len,
			"_setenv() Error: env_var malloc failed");
	envar_len = strlen(na) + strlen(val) + 2;
	*env_var = malloc_char(env_var, envar_len,
			"_setenv() Error: env_var malloc failed");
	strcpy(*env_var, na);
	strcat(*env_var, "=");
	strcat(*env_var, val);
	strcat(*env_var, "\0");
}

/**
 * _env_set_exists - short description
 *
 * Description: long description
 *
 * @env_var: argument_1 description
 * @envar_len: argument_2 description
 * @na: na string
 * @overwrite: overwrite integer
 *
 * Return: return description
 */
int _env_set_exists(char *env_var, unsigned int envar_len, const char *na,
		int overwrite)
{
	unsigned int env_index;

	for (env_index = 0; __environ[env_index]; env_index++)
	{
		if (strncmp(__environ[env_index], na, strlen(na)) == 0 && overwrite != 0)
		{
			free(__environ[env_index]);
			__environ[env_index] = malloc(sizeof(char) * envar_len);
			if (__environ[env_index] == NULL)
			{
				perror("_setenv() Error: __environ[env_index] malloc failed");
				free(env_var);
				return (-1);
			}
			strcpy(__environ[env_index], env_var);
			free(env_var);
			return (0);
		}
	}
	return (0);
}

/**
 * env_does_not_exists - short description
 *
 * Description: long description
 *
 * @env_var: argument_1 description
 * @envar_len: argument_2 description
 * @env_len: length of enviroment
 *
 * Return: return description
 */
int env_does_not_exists(char *env_var, unsigned int envar_len,
		unsigned int env_length)
{
	unsigned int free_new_env_index;
	char **new_environ;

	new_environ = (char **) malloc(sizeof(char *) * (env_length + 2));
	if (new_environ == NULL)
	{
		perror("_setenv() Error: new_environ malloc failed");
		free(env_var);
		return (-1);
	}
	copy_array(new_environ, __environ);
	new_environ[env_length] = malloc(sizeof(char) * envar_len);
	if (new_environ[env_length] == NULL)
	{
		perror("_setenv() Error: new_environ[env_index] malloc failed");
		for (free_new_env_index = 0; free_new_env_index < env_length;
				free_new_env_index++)
			free(new_environ[free_new_env_index]);
		free(new_environ);
		free(env_var);
		return (-1);
	}
	strcpy(new_environ[env_length], env_var);
	new_environ[env_length + 1] = NULL;
	free(env_var);
	__environ = new_environ;
	return (0);
}

/**
 * _setenv - short description
 *
 * Description: The setenv() function adds the variable na to the
 * environment with the val val, if na does not already exist.
 *
 * @na: na string
 * @val: val string
 * @overwrite: overwrite intger
 *
 * Return: -1 on failure 0 on success
 */
int _setenv(const char *na, const char *val, int overwrite)
{
	unsigned int envar_len;
	char *env_var;

	envar_len = strlen(na) + strlen(val) + 2;
	create_envar(&env_var, envar_len, na, val);
	_env_set_exists(env_var, envar_len, na, overwrite);
	if (_env_name_exists(na) != -1)
		_env_set_exists(env_var, envar_len, na, overwrite);
	else
		env_does_not_exists(env_var, envar_len, _env_length());
	return (0);
}
