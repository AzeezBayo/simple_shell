#include "main.h"

/**
 * prompt_read - read prompts and displays inputs
 * @fd_check: the number of byte read by getline
 * Return: user_input
 */

char *prompt_read(ssize_t *fd_check)
{
	char *display_prompt = "$ ";
	char *user_input = NULL;

	/* interactive_mode() */
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, display_prompt, 2);
	}

	user_input = _getline();
	if (user_input == NULL)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}
	*fd_check = s_len(user_input);

	if (*fd_check == -1 && isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "\n", 1);
		free(user_input);
		exit(EXIT_SUCCESS);
	}
	else if (*fd_check == -1)
	{
		free(user_input);
		exit(EXIT_SUCCESS);
	}
	if (*fd_check == 0 && isatty(STDIN_FILENO))
	{
		free(user_input);
		return (prompt_read(fd_check));
	}

	/*write(STDOUT_FILENO, user_input, byte_size);*/
	user_input[_strcspn(user_input, "\n")] = '\0';
	return (user_input);
}
