#include <stdlib.h>

#include "list.h"

struct List* createList()
{
	struct List* list = (struct List*) malloc(sizeof(struct List));
	list->first = NULL;
	list->last = NULL;
	return list;
}

void destroyList(struct List* list)
{
	struct Node* current = list->first;
	while (current != NULL)
	{
		struct Node* next = current->next;
		free(current);
		current = next;
	}
	free(list);
}

void add(struct List* list, int value)
{
	struct Node* node = (struct Node*) malloc(sizeof(struct Node));
	node->value = value;
	node->next = NULL;
	if (list->last == NULL)
	{
		list->first = node;
	}
	else
	{
		list->last->next = node;
	}
	list->last = node;
}