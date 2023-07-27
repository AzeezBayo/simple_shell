#include "main.h"

/**
 * _env - shows all environ datas
 *
 * @shell_data: the environ data
 * Return: when successful returns 1
 */
int _env(data_shell *shell_data)
{
	int i = 0;

	while (shell_data->_environ[i])
	{
		int j = 0;

		while (shell_data->_environ[i][j])
		{
			write(STDOUT_FILENO, &shell_data->_environ[i][j], 1);
			j++;
		}

		write(STDOUT_FILENO, "\n", 1);
		i++;
	}

	shell_data->status = 0;

	return (1);
}

/**
 * handle_env - Handle 'env' command
 * @user_input: User input string
 * @shell_data: Shell data structure
 */

void handle_env(char *user_input, data_shell *shell_data)
{
	free(user_input);
	_env(shell_data);
}
