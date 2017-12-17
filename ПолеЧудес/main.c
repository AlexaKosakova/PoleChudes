#include <stdlib.h>
#include <stdio.h>

#include "list.h"

int main()
{
	struct List* list = createList();
	add(list, 1);
	add(list, 2);
	add(list, 3);
	add(list, 4);
	struct Node* current;
	for (current = list->first; current != NULL; current = current->next)
	{
		printf("%d", current->value);
	}
	destroyList(list);
	getchar();
    return 0;
}