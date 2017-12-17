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

struct List* createList();
void destroyList(struct List* list);
void add(struct List* list, int value);
