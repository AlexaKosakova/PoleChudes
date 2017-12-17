#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "list.h"

char* strrtrim(char* name)
{
	int i = strlen(name) - 1;
	while (isspace(name[i]))
	{
		name[i--] = 0;
	}
	return name;
}

int main()
{
	FILE* p = fopen("players", "r");
	struct List* list = createList();
	char name[50];
	while (fgets(name, sizeof(name), p) != NULL)
	{
		addPlayer(list, strrtrim(name));
	}
	struct Node* current;
	for (current = list->first; current != NULL; current = current->next)
	{
		printf("%s %d\n", current->player.name, current->player.score);
	}
	destroyList(list);
	getchar();
    return 0;
}