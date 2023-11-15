#include "shell.h"

/**
 * cc_setenv - Set the value of an environment variable
 * @args: arguments
 * Return: 0 on success
 */

int cc_setenv(char **args)
{
	char *name, *value;

	if (args[1] == NULL || args[2] == NULL)
	{
		perror("Usage: setenv VARIABLE VALUE\n");
		return (-1);
	}

	name = args[1];
	value = args[2];

	if (setenv(name, value, 1) != 0)
	{
		perror("setenv");
		return (-1);
	}
	return (0);
}

/**
 * cc_unsetenv - Unset an environment variable
 * @args: arguments
 * Return: 0 on sucess
 */

int cc_unsetenv(char **args)
{
	char *name;

	if (args[1] == NULL)
	{
		perror("Usage: unsetenv VARIABLE\n");
		return (-1);
	}

	name = args[1];

	if (unsetenv(name) != 0)
	{
		perror("unsetenv");
	}
	return (0);
}
