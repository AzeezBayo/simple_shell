#include "main.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: string copy to
 * @dup: string to copy
 * Return: pointer to the duplicated string.
 */
char *_strdup(char *dup, char *str)
{
	int i, len;

	if (str == NULL)
		return (NULL);

	len = 0;
	while (str[len])
		len++;

	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		dup[i] = str[i];
	dup[i] = '\0';

	return (dup);
}

/**
 * _strtok - splits a string into a series of tokens
 * @str: string to tokenize
 * @delim: delimiter
 *
 * Return: pointer to the next token, or NULL if there are no more tokens.
 */
char *_strtok(char *str, const char *delim)
{
	static char *saveptr;
	char *token;
	int i, j, len;

	if (str == NULL)
		str = saveptr;

	if (str == NULL)
		return (NULL);

	len = 0;
	while (str[len])
		len++;

	token = malloc(sizeof(char) * (len + 1));
	if (token == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				token[i] = '\0';
				saveptr = &str[i + 1];
				return (token);
			}
		}
		token[i] = str[i];
	}
	token[i] = '\0';
	saveptr = NULL;
	return (token);
}

/**
 * _getenv - searches the environment list to find the environment variable
 * @name: name of the variable to find
 *
 * Return: pointer to the value of the environment variable
 */
char *_getenv(const char *name)
{
	int i, j, len;

	if (name == NULL)
		return (NULL);

	len = 0;
	while (name[len])
		len++;

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; j < len; j++)
		{
			if (environ[i][j] != name[j])
				break;
		}
		if (j == len && environ[i][j] == '=')
			return (&environ[i][j + 1]);
	}

	return (NULL);
}
