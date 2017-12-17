#include <stdlib.h>
#include <string.h>

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

void addPlayer(struct List* list, const char* name)
{
	struct Node* node = (struct Node*) malloc(sizeof(struct Node));
	node->player.name = (char*)malloc(sizeof(char)*strlen(name));
	strcpy(node->player.name, name);
	node->player.score = 0;
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