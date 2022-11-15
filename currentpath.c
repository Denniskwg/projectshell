#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "main.h"

extern char **environ;
int findpath_to_executable(path_h **head) {

	char cwd[PATH_MAX];
	int i = 0, l = 0, k = 0, flag = 0;
	char buffer[1000];
	char *token, *path, *currentposition;

	path_h *ptr;

	if (getcwd(cwd, sizeof(cwd)) != NULL) 
		printf("Current working dir: %s\n", cwd);
	else
	{
		perror("getcwd() error");
		return 1;
	}

	while (environ[i] != NULL)
	{
		if (environ[i][0] == 'P' && environ[i][1] == 'A')
		{
			while (environ[i][l] != '\0')
			{
				buffer[l] = environ[i][l];
				l++;
			}
			buffer[l] = '\0';
			path = buffer;
			shiftcharacter(&path, 5);
			printf("%s\n", path);
			break;
		}
		i++;
	}

	currentposition = path;
	token = tokenizepath(path, ':', &flag, &currentposition);
	while (token != NULL)
	{
		flag++;
		add_node_end(head, token);
		free(token);
		token = tokenizepath(path, ':', &flag, &currentposition);
	}
	ptr = *head;
	while (ptr != NULL)
	{
		printf("NODE(%d) is %s\n", k, ptr->name);
		k++;
		ptr = ptr->next;
	}
	printf("PATH still is %s\n", path);
	return (0);

}
char *tokenizepath(char *p, char delimiter, int *flag, char **a)
{
	char *token = malloc(sizeof(char) * 100);
	int i = 0, k = 0;
	int numberoftokens = 0;

	if (p == NULL)
		return (NULL);

	while (p[k] != '\0')
	{
		if (p[k] == delimiter)
			numberoftokens++;
		k++;
	}
	if (numberoftokens == 0)
	{
		free(token);
		return (NULL);
	}
	numberoftokens++;
	while (*(*a) != '\0')
	{
		if (*(*a) == delimiter)
		{
			(*a)++;
			break;
		}
		token[i] = *(*a);
		i++;
		(*a)++;
	}
	if (*(*a) == '\0' && numberoftokens == *flag)
		return (NULL);
	token[i] = '\0';
	return (token);
}
void shiftcharacter(char **t, int n)
{
	if (t == NULL)
		return;
	while (n > 0)
	{
		(*t)++;
		n--;
	}
}
void copystring2(char *s, char *s1)
{
	int i = 0;
	if (s == NULL)
		return;

	while (s[i] != '\0')
	{
		s1[i] = s[i];
		i++;
	}
	s1[i] = '\0';
}


path_h *add_node_end(path_h **head, char *str)
{
	path_h *ptr, *lastnode;

	if (head == NULL)
		return (NULL);

	ptr = malloc(sizeof(path_h));

	if (ptr == NULL)
		return (NULL);

	copystring2(str, ptr->name);
	ptr->next = NULL;

	if (*head == NULL)
		*head = ptr;
	else
	{
		lastnode = *head;
		while (lastnode->next != NULL)
		{
			lastnode = lastnode->next;
		}
		lastnode->next = ptr;
	}
	return (ptr);

}


