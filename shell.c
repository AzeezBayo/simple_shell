#include "main.h"
/**
 * main - shell clone
 * @ac: argument count
 * @argv: array of pointer to strings
 * Return: 1 or 0
 */
int main(int ac, char **argv)
{
	char *user_input, **receive_argv;
	ssize_t fd_check;
	int i, execution_status = 0;
	data_shell shell_data;

	shell_data._environ = environ;
	(void)ac;
	(void)argv;

	while (1 == 1)
	{
		user_input = NULL, fd_check = 0;
		user_input = prompt_read(&fd_check);
		receive_argv = tokenization(user_input, receive_argv, fd_check);
		if (receive_argv[0] == NULL)
			continue;
		if (_strcmp(receive_argv[0], "env") == 0)
		{	free(user_input);
			_env(&shell_data);
			free_array(receive_argv);
			continue;	}
		if (_strcmp(receive_argv[0], "exit") == 0)
		{	free(user_input);
			exit_shell(receive_argv, execution_status);
			free_array(receive_argv);
			continue;
		}
		i = handle_env_commands(receive_argv);
		if (i != 0)
		{	free(user_input);
			free_array(receive_argv);
			continue;
		}
		execution_status = execute_command(receive_argv);
		if (execution_status == 1)
			print_error(receive_argv, "not found\n");
		free(user_input);
		free_array(receive_argv);
	}
	return (0);
}
