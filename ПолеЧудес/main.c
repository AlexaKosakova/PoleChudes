#include <stdlib.h>
#include <stdio.h>

#include "list.h"

int main()
{
	struct List* list = createList();
	addPlayer(list, "Sasha");
	addPlayer(list, "Sasha1");
	addPlayer(list, "Sasha2");
	addPlayer(list, "Sasha3");
	struct Node* current;
	for (current = list->first; current != NULL; current = current->next)
	{
		printf("%s %d\n", current->player.name, current->player.score);
	}
	destroyList(list);
	getchar();
    return 0;
}