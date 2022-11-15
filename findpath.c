#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <dirent.h>
#include <limits.h>
#include "main.h"



char *findpath(char *file, path_h *head)
{
	struct dirent *ent;
	DIR *folder;
	path_h *ptr;
	int found = 0;
	ptr = head;
	while (ptr != NULL && ptr->name != NULL)
	{
		folder = opendir(ptr->name);
		if (folder == NULL)
		{
			ptr = ptr->next;
			continue;
		}
		while ((ent = readdir(folder)) != NULL)
		{
			if ((comparestrings(file, ent->d_name)) == 0)
			{
				found = 1;
				break;
			}
		}
		closedir(folder);
		if (found == 1)
			break;
		ptr = ptr->next;
	}
	if (found == 1)
		return (ptr->name);
	return (NULL);
}

int comparestrings(char *a, char *b)
{
	int i = 0;
	if (a == NULL || b == NULL)
		return (1);
	while (a[i] != '\0' && b[i] != '\0')
	{
		if (a[i] == b[i])
			i++;
		else
			return (1);
	}
	return (0);
}
