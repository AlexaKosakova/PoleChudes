#include <stdlib.h>

struct Node
{
	int value;
	struct Node* next;
};
struct List
{
	struct Node* first;
	struct Node* last;
};
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