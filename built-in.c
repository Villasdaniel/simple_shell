#include "holberton.h"
/**
 * _myexit - check command line to exit shell
 * @line: command line
 * Return: 0 (Success) 1 (Fail)
 **/
int _myexit(char *line)
{
	char *exit_line = "exit";
	int i = 0;
	int len = _strlen(line);

	if (len == 4)
	{
		while (exit_line[i])
		{
			if (exit_line[i] != line[i])
				return (1);
			i++;
		}
		free(line);
		return (0);
	}
	return (1);
}
/**
 * signal_c - Ignore input signal Ctrl + C
 * @sign: siganal parameter
 **/
void signal_c(int sign)
{
	signal(sign, SIG_IGN);
	write(STDOUT_FILENO, "\n#cisfun$ ", 11);
	signal(SIGINT, signal_c);
}
/**
 * _myenv - print the environment variables separated.
 * @line: The command line.
 * Return: 0 if succes or 1 if fails.
 **/
int _myenv(char *line)
{
	char *env_line = "env";
	int i = 0, j;
	int len = _strlen(line);

	if (len == 3)
	{
		while (env_line[i])
		{
			if (env_line[i] != line[i])
				return (1);
			i++;
		}
		for (i = 0; environ[i] != NULL; i++)
		{
			for (j = 0; environ[i][j] != '\0'; j++)
			{
				write(STDOUT_FILENO, &environ[i][j], 1);
			}
			write(STDOUT_FILENO, "\n", 1);
		}
		return (0);
	}
	return (1);
}
