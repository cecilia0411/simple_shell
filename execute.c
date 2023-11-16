#include "shell.h"

/**
  * execute_cmd - executes the input from the buffer
  * @input: a pointer
  * @argv: argumnet pointer
  * @env: pointer to an adress
  */

void execute_cmd(char *input, char *argv[], char **env)
{
	char *args[100];
	char *path, *name;
	int status, num;
	pid_t child_pid;

	name = argv[0];
	num = tokenize(input, args);

	if (num == 0)
		return;
	if (handle_builtin(args, num, input, env) == 1)
		return;
	path = get_path(args[0]);

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error: Failed fork");
		free(input);
		exit(1);
	}

	if (child_pid == 0)
	{
		if (execve(path, args, NULL) == -1)
		{
			write(2, name, _strlen(name));
			write(2, ": 1: ", 5);
			write(2, args[0], _strlen(args[0]));
			write(2, ": not available\n", 16);
			exit(127);
		}
	}
	else
		wait(&status);

	free(path);
}
