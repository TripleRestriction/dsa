#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
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
// my implementations

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
		// for the last element in the list
		else {
			node *newNode = (node*)malloc(sizeof(node));
			headPtr->next = newNode;
			newNode->next = NULL;
			newNode->data = value;
			return newNode;
		}
	}
}

node* deletion(node *headPtr, size_t index){
	if (index == 0){
		// delete the head
		node *newHead = headPtr->next;
		free(headPtr);
		return newHead;
	}
	else {
		// for any other index
		node *newLast;
		for(size_t i = 0; i < index-1; i++){
			// for the delete the last case, we need to save the pointer
			headPtr = headPtr->next;
			if (headPtr->next->next == NULL) {
				newLast = headPtr;
			}
			else {
				newLast = NULL;
			}
		}
		if(headPtr->next != NULL){
			node *ptr = headPtr->next;
			headPtr->next = headPtr->next->next;
			free(ptr);
			return headPtr->next;
		}
		else {
			// for last node
			free(headPtr);
			newLast->next = NULL;
			return 0;
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
	printf("deleting head\n");
	head = deletion(head, 0);
	traversal(head);
	printf("deleting element\n");
	node *ptr = deletion(head, 1);
	traversal(head);
	printf("deleting last element\n");
	deletion(head, 2);
	traversal(head);
	return 0;
}
