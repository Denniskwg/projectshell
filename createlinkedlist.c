#include "main.h"
#include <stdlib.h>

void createlinkedlist(char *buff, path_h **head)
{
	char *currentposition = buff;
	char *token;
	int flag = 0;

	token = tokenizepath(buff, ':', &flag, &currentposition);
	while (token != NULL)
	{
		flag++;
		add_node_end(head, token);
		free(token);
		token = tokenizepath(buff, ':', &flag, &currentposition);
	}
}
