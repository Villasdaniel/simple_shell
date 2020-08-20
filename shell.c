#include "holberton.h"
/**
 * main - Entry point for shell
 * Return: 0 (Return value)
 */
int main(void)
{
	int status_output = 0;
	int read = 1;
	while (read)
	{
		char *command_line = NULL, **argm = NULL;
		size_t line_size = 0;
		
		signal(SIGINT, signal_c);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 10);
		read = _getline(&command_line, &line_size, stdin);
		if (read == 0)
		{
			free(command_line);
			continue;
		}
		if (read < 0)
		{
			free(command_line);
			exit(status_output);
		}
		if (read != EOF)
		{
			if (_myexit(command_line) == 0)
			{
				free(command_line);
				return(status_output);
			}
			_myenv(command_line);
			argm = splitline(command_line);
			status_output = execute_process(argm);
			free(command_line);
		}	
	}
	return (status_output);
}