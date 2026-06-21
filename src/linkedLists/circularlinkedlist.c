// linked list but last element points back to the head
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}node;

void traversal(node *headPtr){
	node* q = headPtr;
	do{
		printf("element: %d\n", headPtr->data);
		headPtr = headPtr->next;
	}while(q!=headPtr);
}

node* insertAtHead(node *headPtr, int value){
	node *newHead = (node*)malloc(sizeof(node));
	newHead->data = value;
	node *q = headPtr;
	while (headPtr->next != q) {
		headPtr = headPtr->next;
	}
	newHead->next = q;
	headPtr->next = newHead;
	return newHead;
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
	third->next = head; // instead of null
	traversal(head);
	printf("After:\n");
	head = insertAtHead(head, 1337);
	traversal(head);
	return 0;
}
