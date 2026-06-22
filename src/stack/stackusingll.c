#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}node;

typedef struct stack{
	node *top;
	int nodes;
}stack;

stack createStack(int value){
	node *ptr = (node*)malloc(sizeof(node));
	ptr->data = value;
	stack s = {ptr, 1};
	return s;
}

void popOffStack(stack *s){
	if(s->top == NULL){
		printf("Stack is empty\n");
		exit(1);
	}	
	node *ptr = s->top;
	s->top = ptr->next;
	free(ptr);
	s->nodes--;
}

void printTopValue(stack *s){
	if(s->top != NULL) printf("%d\n", s->top->data);
}

void pushOnStack(stack *s, int value){
	node *ptr = (node*)malloc(sizeof(node));
	ptr->data = value;
	ptr->next = s->top;
	s->top = ptr;
	s->nodes++;
}

int main(int argc, char *argv[])
{
	stack myStack = createStack(67);
	printTopValue(&myStack);
	popOffStack(&myStack);
	printTopValue(&myStack);
	pushOnStack(&myStack, 69);
	printTopValue(&myStack);
	pushOnStack(&myStack, 1337);
	printf("%d\n", myStack.nodes);
	printTopValue(&myStack);
	popOffStack(&myStack);
	printf("%d\n", myStack.nodes);
	printTopValue(&myStack);
	popOffStack(&myStack);
	printf("%d\n", myStack.nodes);
	return 0;
}
