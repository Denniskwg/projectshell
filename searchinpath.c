#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <dirent.h>
#include <limits.h>
#include "main.h"



char *searchpath(char *file, char *path)
{
	struct dirent *ent;
	DIR *folder;
	int found = 0;

	folder = opendir(path);
	if (folder == NULL)
	{
		closedir(folder);
		return (NULL);
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
		return (path);
	return (NULL);
}

