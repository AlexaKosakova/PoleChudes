#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

void game()
{
	FILE* q = fopen("questions", "r");
	char que[100], ans[100], word[100], s[2];
	char w;
	int count, i, n, k = 0, win, a[3];
	fgets(que, sizeof(que), q); //считывается вопрос
	fgets(ans, sizeof(ans), q); //считывается ответ
	count = strlen(ans); //длинна ответа
	for (i = 0; i < count; i++)
	{
		word[i] = '*'; //заполняем нулями массив
	}
	word[i] = 0;
	printf("%s", que);
	printf("%s", word);
	printf("\n");
	while (strchr(word, '*') != NULL)
	{
		for (n = 0; n < 3; n++)
		{
			for (;;)
			{
				printf("Player №%d\n", n + 1);
				gets(s, 1);
				w = s[0];
				for (i = 0; i < count; i++)
				{
					if (ans[i] == w && word[i] != w)
					{
						word[i] = w;
						a[n] += rand() % 1000 + 100;
						k = 1;
					}
				}
				printf("%s\n", word);
				if (k == 1)
				{
					k = 0;
					if (strchr(word, '*') == NULL)
					{
						win = a[n];
						printf("The winner is player №%d\n", n + 1);
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
	printf("Congratulations!\n The right word was %s.", word);
	getchar();
}