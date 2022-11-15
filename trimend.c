#include <stdio.h>
#include <stdlib.h>
#include "main.h"


void trim_end(char **str)
{
	char *p;
	int i = 0, spaces = 0;

	while ((*str)[i] != '\0' && (*str)[i] != '\n')
	{
		p = &((*str)[i]);
		if (*p == ' ')
			++spaces;
		i++;
	}
	if ((*p > 64 && *p < 91) || (*p > 96 && *p < 123))
	{
		p++;
		*p = '\0';
		return;
	}
	p -= spaces;
	p++;
	*p = '\0';
}
