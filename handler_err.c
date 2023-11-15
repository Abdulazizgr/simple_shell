#include "shell.h"
/**
 * handle_signal - handle EOF signal
 * @sign: EOF indication
 * Return: void
 */
void handle_signal(int sign)
{
(void) sign;
cout("\nzizu$ ");
fflush(stdout);
}
/**
 * _stat - get file status
 * @cmd: array of commands
 * @dir: array of directory paths
 * Return: 1 on success
 **/
int _stat(char **cmd, char **dir)
{
char *con = NULL, *new_con = NULL;
int ret;
struct stat sb;
if (dir == NULL)
{
free(dir);
free(cmd);
return (0);
}
for (ret = 0; dir[ret] != NULL; ret++)
{
con = str_concat(dir[ret], "/");
new_con = str_concat(con, cmd[0]);
if (stat(new_con, &sb) == 0 && (sb.st_mode & S_IXUSR))
{
cmd[0] = new_con;
free(con);
free(dir[0]);
free(dir);
return (1);
}
free(con);
free(new_con);
}
free(dir[0]);
free(dir);
return (0);
}
/**
 * _error - prints the error output
 * @argv: name of program
 * @count: num of prompt
 * @args: command to be put in
 * Return: 0 on success
 */
int *_error(char *argv, int count, char *args)
{
char *num;
num = _itoa(count, 10);
write(2, argv, _strlen(argv));
write(2, ": ", 2);
write(2, num, _strlen(num));
write(2, ": ", 2);
write(2, args, _strlen(args));
perror(" ");
return (0);
}
