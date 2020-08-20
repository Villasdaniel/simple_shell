#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>

/**
 * struct link - node that contains the directories
 * @dir: directory
 * @next: position to change the node
 */
typedef struct link
{char *dir;
struct link *next;
} link_t;

extern char **environ;
char *_getenv(const char *name);
char *_strtok(char *str, char *delim);
int _getline(char **bufline, size_t *size, FILE *std);
char **splitline(char *command_line);
void signal_c(int sign);
int _myexit(char *line);
int _strlen(char *s);
int execute_process(char **argm);
link_t *_add_nodeint_end(link_t **head, char *n);
size_t _print_listint(link_t *h);
link_t *_link(char *a);
char *_strcat(char *directory, char *slash, char *arg);
char *_which(link_t **head, char *av);
void free_list(link_t *head);
int _myenv(char *line);
#endif