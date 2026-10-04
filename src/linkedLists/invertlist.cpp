#include <iostream>

typedef struct node {
	int data;
	struct node *next;
} node;

void traversal(node *root)
{
	while (root != nullptr) {
		std::cout << root->data << std::endl;
		root = root->next;
	}
}

void invert(node*& root)
{
	node *current = nullptr;
	node *previous = nullptr;
	node *nxt = nullptr;
	while (root != nullptr) {
		current = root;
		nxt = root->next;
		root = root->next;
		current->next = previous;
		previous = current;
	}
	root = previous;
}

int main()
{
	node *first = new node;
	node *second = new node;
	node *third = new node;

	first->data = 67;
	first->next = second;
	second->data = 69;
	second->next = third;
	third->data = 420;
	third->next = nullptr;
	traversal(first);
	invert(first);
	std::cout << "after\n";
	traversal(first);
}
