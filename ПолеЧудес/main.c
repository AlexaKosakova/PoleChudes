#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

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
struct Prize
{
	char object[20];
	int price;
};

int main()
{
	srand((unsigned)time(NULL));

	FILE* q = fopen("questions", "r");
	char question[100], answer[100];
	fgets(question, sizeof(question), q);
	fgets(answer, sizeof(answer), q);
	fclose(q);

	FILE* p = fopen("players", "r");
	struct List* players = createList();
	char name[50];
	while (fgets(name, sizeof(name), p) != NULL)
	{
		addPlayer(players, strrtrim(name));
	}
	fclose(p);

	struct Player* winner = game(players, question, answer);

	FILE* pr = fopen("prize", "r");
	struct Prize prize[20];
	int i, n, prz, score, gift[20];
	for (i = 0; feof(pr) == 0 ; i++)
	{
		fscanf(pr, "%s %d", prize[i].object, &prize[i].price);
	}
	n = i;
	fclose(pr);

	printf("Lets choose the prize!\n");
	for (i = 0; i < n; i++)
	{
		printf("%d - %s %d\n", i+1, prize[i].object, prize[i].price);
		gift[i] = 0;
	}
	printf("Input prize number. If you want to finish, print 0.\n");
	
	score = winner->score;
	while (score >= 0)
	{
		scanf("%d", &prz);
		if (prz == 0)
		{
			break;
		}
		else if (prz > n)
		{
			printf("Wrong number!\n");
		}
		else if (score < prize[prz - 1].price)
		{
			printf("You can't choose %s!\n", prize[prz - 1].object);
		}
		else
		{
			score -= prize[prz - 1].price;
			printf("You choose %s.\n", prize[prz - 1].object);
			gift[prz - 1] += 1;
		}
		printf("You have %d score!\n", score);
	}
	printf("You have choosen:\n");
	for (i = 0; i < n; i++)
	{
		if (gift[i] != 0)
		{
			printf("%s %d\n", prize[i].object, gift[i]);
		}
	}
	destroyList(players);
	getch();
    return 0;
}