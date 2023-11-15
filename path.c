#include "shell.h"

/**
  * check_slash - Checks if file starts with "/"
  * @str: pointer
  *
  * Return: 0 on success, otherwise failure
  */

int check_slash(const char *str)
{
	if (str != NULL || str[0] == '/')
		return (1);

	return (0);
}

/**
  * path_cmd - get the executable path of file
  * @path: pointer to path variable
  * @cmd: executable file
  * Return: the path to the executable file
  */

char *path_cmd(char *path, char *cmd)
{
	char *name, *token;
	struct stat status;
	char *path_buff = NULL;

	name = _strdup(path);
	token = _strtok(name, ":");

	while (token)
	{
		if (path_buff)
		{
			free(path_buff);
			path_buff = NULL;
		}
		path_buff = malloc(_strlen(token) + _strlen(cmd) + 2);
		if (!path_buff)
		{
			perror("Command failed");
			exit(EXIT_FAILURE);
		}
		_strcpy(path_buff, token);
		_strcat(path_buff, "/");
		_strcat(path_buff, cmd);
		_strcat(path_buff, "\0");

		if (stat(path_buff, &status) == 0 && access(path_buff, X_OK) == 0)
		{
			free(name);
			return (path_buff);
		}
		token = _strtok(NULL, ":");
	}
	free(name);
	if (path_buff)
		free(path_buff);
	return (NULL);
}

/**
  * get_path - it gets the full path of the file
  * @name: pointer to adress
  *
  * Return: to a pointer
  */

char *get_path(char *name)
{
	char *path = getenv("PATH");
	char *value;


	if (check_slash(name) &&
			access(name, X_OK) == 0)
		return (_strdup(name));

	if (!path)
	{
		perror("Path unavailable");
		return (NULL);
	}

	value = path_cmd(path, name);

	if (value == NULL)
	{
		write(2, name, _strlen(name));
		write(2, "Error: command unavailable\n", 26);
		return (NULL);
	}

	return (value);
}

/**
  * handle_hashtag - handles the '#' in the input
  * @name: pointer specifier
  * Return: to a pointer
  */

char *handle_hashtag(char *name)
{
	char *hashtag;

	hashtag = _strstr(name, " #");

	if (hashtag)
	{
		*hashtag = '\0';
	}

	return (name);
}
