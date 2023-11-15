#include "shell.h"

/**
  * cc_tokenize - tokenizes the input strings
  * @line: pointer to parse
  * @args: array of strings
  * Return: to a pointer
  */

int cc_tokenize(char *line, char *args)
{
	int tokens;
	char *token;

	tokens = 0;
	token = _strtok(line, " \n");

	while (token)
	{
		args[tokens] = token;
		token = _strtok(NULL, " \n");
		tokens++;
	}

	args[tokens] = NULL;
	return (tokens);
}
