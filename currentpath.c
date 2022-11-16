#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "main.h"

extern char **environ;
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
	{
		free(token);
		return (NULL);
	}
	token[i] = '\0';
	return (token);
}
char *shiftcharacter(char **t, int n)
{
	char *ptr = *t;
	if (t == NULL)
		return (NULL);
	while (n > 0)
	{
		ptr++;
		n--;
	}
	return (ptr);
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


