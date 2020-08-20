#include "holberton.h"
/**
 * _getenv - find the env vari. name
 * @name: variable name
 * Return: NULL if fails or pointer to value of env.var.
 */
char *_getenv(const char *name)
{
	int i;
	int j;
	char *a;

	for (i = 0 ; environ[i] != NULL ; i++)
	{
		for (j = 0 ; name[j] == environ[i][j] && name[j] != '\0' ; j++)
		{
			if (name[j + 1] == '\0')
			{
				a = &environ[i][j + 2];
				return (a);
			}
		}
	}
	return (NULL);
}
/**
 * _getline - get line command line from the prompt
 * @bufline: command buffer line string.
 * @size: size of the command buffer lines.
 * @std: file stream where comes the command buffer line.
 * Return: number of bytes copied in the buffer.
 **/
ssize_t _getline(char **bufline, size_t *size, FILE *std)
{
	size_t count = 0;
	size_t alloc = 1024;
	char c;

	if (!bufline || !size || !std)
		return (-1);
	if (*bufline == NULL)
	{
		*bufline = malloc(alloc);
		if (!(*bufline))
			return (-1);
	}
	while ((c = getchar()) != EOF)
	{
		if (c == '\n')
			break;
		count++;
		(*bufline)[count - 1] = c;
	}
	if (c == EOF)
	{
		return (-1);
	}
	(*bufline)[count] = '\0';
	return (count);
}
/**
* splitline - get line command line from the prompt
* @command_line: command line string.
* Return: a pointer to string of command strings.
**/
char **splitline(char *command_line)
{
	char **ptrstr;
	char *del = " ";
	int size = 100;
	int position = 0;
	char *word;

	ptrstr = malloc(sizeof(char *) * size);
	if (ptrstr == NULL)
		exit(EXIT_FAILURE);
	word = _strtok(command_line, del);
	while (word != NULL)
	{
		ptrstr[position++] = word;
		word = _strtok(NULL, del);
	}
	ptrstr[position] = NULL;
	return (ptrstr);
}
/**
 * execute_process - execute process function
 * @argm: arguments from command_line
 * Return: 0 (Success) -1 (Failed)
 **/
int execute_process(char **argm)
{
	pid_t child_process;
	int status;
	char *path = NULL;
	link_t *head = NULL;
	char *buffer = NULL;
	int status_output = 0;
	
	path = _getenv("PATH");
	printf("%s\n", path);
	head = _link(path);
	buffer = _which(&head, argm[0]);
	child_process = fork();
	printf("este es el proceso: %i\n", child_process);
	if (buffer == NULL)
	{
		perror("error");
		/*free(buffer);
		free_array(argm);
		free_list(head);*/
		return (1);
	}
	if (child_process < 0)
	{
		printf("child_process: %i", child_process);
		exit(errno);
	}
	else if (child_process == 0)
	{
		if (execve(buffer, argm, environ) == -1)
		{
			perror("./shell");
			exit(errno);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			status_output = WEXITSTATUS(status);
		}
		/*free(buffer);
		free(argm);*/
		/*free_list(head);*/
	}
	return (status_output);
}
/**
 * _which - search ofr a command in the directories
 * @head: head
 * @av: arguments
 * Return: path of a command or nil
 **/
char *_which(link_t **head, char *av)
{
	struct stat st;
	link_t *pusher = *head;
	char *buffer;

	if (stat(av, &st) == 0)
		return (av);
	while (pusher)
	{
		buffer = _strcat(pusher->dir, "/", av);
		printf("%s\n", buffer);
		if (stat((const char *)buffer, &st) == 0)
		{
			return (buffer);
		}
		/*free(buffer);*/
		pusher = pusher->next;
	}
	return (NULL);
}
