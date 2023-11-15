#include "shell.h"

/**
  * display_prompt - displays the prompt of the user
  */

void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "CcShell$ ", 9);
}
