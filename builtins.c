#include "shell.h"

/**
  * print_env - prints the environment variables
  * @env: pointer to address
  */

void print_env(char **env)
{
	while (*env != NULL)
	{
		write(1, *env, _strlen(*env));
		write(1, "\n", 1);
		env++;
	}
}

/**
 * change_dir - Changes directory
 * @cmd: Parsed command
 * Return: 0 on success 1 if failed (For OLDPWD Always 0 incase of no OLDPWD)
 */

int change_dir(char **cmd)
{
	int value = -1;
	char cwd[PATH_MAX];

	if (cmd[1] == NULL)
		value = chdir(getenv("HOME"));
	else if (_strcmp(cmd[1], "-") == 0)
	{
		value = chdir(getenv("OLDPWD"));
	}
	else
		value = chdir(cmd[1]);

	if (value == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (value != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}

/**
 * handle_builtin - handles builtin function
 * @args: pointer to check if it's a builtin
 * Return: 1 on success, 0 otherwise
 */

int handle_builtin(char **args)
{
	if (!args[0])
		return (0);
	if (!_strcmp(args[0], "exit"))
		cc_exit(args);
	else if (!_strcmp(args[0], "env"))
		print_env(args);
	else if (!_strcmp(args[0], "setenv"))
		cc_setenv(args);
	else if (!_strcmp(args[0], "unsetenv"))
		cc_unsetenv(args);
	else if (!_strcmp(args[0], "cd"))
		change_dir(args);
	else
		return (0);
	return (1);
}
