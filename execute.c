#include "main.h"
/**
 * execute_command - execute user's command
 * @receive_argv: array to pointer of strings
 * Return: nothing
 */
int execute_command(char **receive_argv)
{
	char *first_command, *final_cmd;
	pid_t child_process;
	int process_status = 0;

	first_command = NULL;
	final_cmd = NULL;
	child_process = -1;
	first_command = receive_argv[0];
	final_cmd = get_path(first_command);

	if (final_cmd == NULL)
		return (1);
	if (receive_argv && access(final_cmd, X_OK) != -1)
	{
		child_process = fork();

		if (child_process == -1)
		{
			print_error(receive_argv, "command not found\n");
		}
		else if (child_process == 0)
		{

			if (execve(final_cmd, receive_argv, NULL) == -1)
				print_error(receive_argv, "command not found\n");

		}
		else
		{
			if (waitpid(child_process, &process_status, 0) == -1)
				print_error(receive_argv, "command not found\n");
		}
		if (_strcmp(final_cmd, first_command) != 0)
			free(final_cmd);
		if (WIFEXITED(process_status))
			process_status = WEXITSTATUS(process_status);
		return (process_status);
	}
	free(final_cmd);
	return (1);
}
