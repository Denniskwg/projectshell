#include "main.h"
#include <stdio.h>

char *getlaststring(char **buf)
{
	char *p;
	char *last;
	int i = 0, j = 0;

	while ((*buf)[i] != '\0')
	{
		p = &((*buf)[i]);
		if (*p == '/')
			j++;
		i++;
	}
	if (j == 0)
		return (*buf);
	while (*p != '/')
	{
		p--;
		i--;
		if (i == 0)
			return (NULL);
	}
	*p = '\0';
	p++;
	last = p;
	return (last);
}
