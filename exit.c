#include "shell.h"

/**
  * cc_exit - handles the exit status
  * @ar: argument count
  * @str: checks the status of exit
  *
  * Return: exit status, 1 if otherwise
  */

int cc_exit(char **ar, char *str)
{
	char *index;
	int status, i;

	if (ar[1] != NULL)
	{
		status = 0;
		index = ar[1];

		for (i = 0; index[i] != '\0'; i++)
		{
			if (index[i] < '0' || index[i] > '9')
			{
				h_exit(str, 2);
				return (1);
			}
			status = status * 10 + (index[i] - '0');
		}
		h_exit(str, status);
	}
	else
	{
		h_exit(str, 127);
	}
	return (1);
}

/**
  * h_exit - handles the exit function
  * @index: index value
  * @status: exits the status of the code
  */

void h_exit(char *index, int status)
{
	free(index);
	exit(status);
}
