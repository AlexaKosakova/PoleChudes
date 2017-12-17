#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#include "list.h"

void game(const struct List* players, const char* question, const char* answer)
{
	char word[100], s[2];
	char w;
	int count, i, n, k = 0;
	struct Player* winner;

	count = strlen(answer);
	for (i = 0; i < count; i++)
	{
		word[i] = '*';
	}
	word[i] = 0;
	printf("%s", question);
	printf("%s", word);
	printf("\n");
	while (strchr(word, '*') != NULL)
	{
		struct Node* current;
		for (current = players->first; current != NULL; current = current->next)
		{
			for (;;)
			{
				int score = rand() % 1000 + 100;
				printf("Player %s. Score %d!\n", current->player.name, score);
				gets(s, 1);
				w = s[0];
				for (i = 0; i < count; i++)
				{
					if (answer[i] == w && word[i] != w)
					{
						word[i] = w;
						current->player.score += score;
						k = 1;
					}
				}
				printf("%s\n", word);
				if (k == 1)
				{
					k = 0;
					if (strchr(word, '*') == NULL)
					{
						winner = &current->player;
						break;
					}
				}
				else
					break;
			}
			if (strchr(word, '*') == NULL)
				break;
		}
	}
	printf("Congratulations!\n");
	printf("The winner is %s with %d score!\n", winner->name, winner->score);
	printf("The right word was %s.\n", word);
	struct Node* current;
	for (current = players->first; current != NULL; current = current->next)
	{
		printf("%s %d\n", current->player.name, current->player.score);
	}
	getchar();
}