#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}node;

void traversal(node *headPtr){
	while(headPtr!=NULL){
		printf("element: %d\n", headPtr->data);
		headPtr = headPtr->next;
	}
}
// my implementation
node* insertion(node *headPtr, size_t index, int value){
	if(index == 0){
		// change the head
		node *newHead = (node*)malloc(sizeof(node));
		newHead->next = headPtr;
		newHead->data = value;
		return newHead;
	}
	else {
		// for any other index
		for(size_t i = 0; i < index-1; i++){
			headPtr = headPtr->next;
		}
		if(headPtr->next != NULL){
			node *newNode = (node*)malloc(sizeof(node));
			newNode->next = headPtr->next;
			headPtr->next = newNode;
			newNode->data = value;
			return newNode;
		}
		else {
			node *newNode = (node*)malloc(sizeof(node));
			headPtr->next = newNode;
			newNode->next = NULL;
			newNode->data = value;
			return newNode;
		}
	}
}

int main(int argc, char *argv[])
{
	node *head = (node*)malloc(sizeof(node));
	node *second = (node*)malloc(sizeof(node));
	node *third = (node*)malloc(sizeof(node));

	head->data = 69;
	head->next = second;

	second->data = 67;
	second->next = third;

	third->data = 420;
	third->next = NULL;
	traversal(head);
	printf("Changing head\n");
	head = insertion(head, 0, 1337);
	traversal(head);
	printf("Inserting new node\n");
	node *newnode = insertion(head, 3, 40);
	traversal(head);
	return 0;
}
