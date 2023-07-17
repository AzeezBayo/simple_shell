#include "main.h"
/**
 * get_path - get the path of each command
 * @first_command: user input
 * Return: command path
 */
char *get_path(char *first_command)
{
	struct stat path_test;
	char *cmd_path, *cmd_path_copy = NULL, *delimiter;
	char *path_to_file, *parse_token;
	int dir_len, length_user_command, path_to_file_len, i;

	delimiter = ":";
	cmd_path = _getenv("PATH");

	if (stat(first_command, &path_test) == 0)
		return (first_command);

	if (cmd_path)
	{	cmd_path_copy = _strdup(cmd_path_copy, cmd_path);
		length_user_command = s_len(first_command);
		parse_token = _strtok(cmd_path_copy, delimiter);

		while (parse_token != NULL)
		{
			dir_len = s_len(parse_token);
			path_to_file_len = length_user_command + dir_len + 2;
			path_to_file = malloc(path_to_file_len);
			path_to_file[0] = '\0';
			for (i = 0; i < path_to_file_len; i++)
				path_to_file[i] = '\0';
			s_copy(path_to_file, parse_token);
			s_cat(path_to_file, "/");
			s_cat(path_to_file, first_command);
			s_cat(path_to_file, "\0");
			if (stat(path_to_file, &path_test) == 0)
			{	free(cmd_path_copy);
				free(parse_token);
				return (path_to_file);
			}
			free(path_to_file);
			free(parse_token);
			parse_token = _strtok(NULL, delimiter);
		}
	}
	free(cmd_path_copy);
	return (NULL);
}
