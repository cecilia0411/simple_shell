#include "shell.h"

/**
  * tokenize - tokenizes the input strings
  * @str: pointer
  * @line: the array of strings
  *
  * Return: Number of the items tokenized
  */

char *tokenize(char *str, char *line)
{
	int count;
	char *token;

	count = 0;
	token = strtok(input, " \n");

	while (token)
	{
		args[count] = token;
		token = strtok(NULL, " \n");
		count++;
	}

	args[count] = NULL;
	return (count);
}
