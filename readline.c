#include "shell.h"

/**
* cc_readline - reads input from standard input by user
* Return: the input on a buffer
*/

char *cc_readline(void)
{
	char *line;
	size_t buflen;
	ssize_t nread;

	line = NULL;
	buflen = 0;
	nread = getline(&line, &buflen, stdin);

	if (nread == -1)
	{
		free(line);
		exit(0);
	}
}
