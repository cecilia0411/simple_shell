#include "shell.h"

/**
  * main - Wait program
  * @argc: Argumnt count
  * @argv: Array of arguments
  * @env: Environment variable
  *
  * Return: O Always succes
  */

int main(int argc, char *argv[], char **env)
{
	char *input;
	(void)argc;

	while (1)
	{
		display_prompt();
		input = cc_readline();
		execute_cmd(input, argv, env);
		free(input);
	}

	return (0);
}
