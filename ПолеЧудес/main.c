#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "list.h"
#include "game.h"

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
	FILE* q = fopen("questions", "r");
	char question[100], answer[100];
	fgets(question, sizeof(question), q);
	fgets(answer, sizeof(answer), q);

	FILE* p = fopen("players", "r");
	struct List* players = createList();
	char name[50];
	while (fgets(name, sizeof(name), p) != NULL)
	{
		addPlayer(players, strrtrim(name));
	}

	game(players, question, answer);

	destroyList(players);
	getchar();
    return 0;
}