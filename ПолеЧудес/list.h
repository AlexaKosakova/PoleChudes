#include "player.h"

struct Node
{
	struct Player player;
	struct Node* next;
};
struct List
{
	struct Node* first;
	struct Node* last;
};

struct List* createList();
void destroyList(struct List* list);
void addPlayer(struct List* list, const char* name);
