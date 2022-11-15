#include <stdlib.h>
#include "main.h"
void free_list(path_h *head)
{
	path_h *ptr;

	if (head == NULL)

		return;

	while (head != NULL)
	{
		ptr = head;
		free(ptr->name);
		head = head->next;
		free(ptr);
	}
}
