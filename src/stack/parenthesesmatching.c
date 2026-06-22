#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
	char data;
	struct node *next;
}node;

typedef struct stack{
	node *top;
}stack;

stack createStack(){
	stack s = {NULL};
	return s;
}

void popOffStack(stack *s){
	if(s->top == NULL){
		printf("unbalanced\n");
		exit(1);
	}	
	node *ptr = s->top;
	s->top = ptr->next;
	free(ptr);
}

void printTopValue(stack *s){
	if(s->top != NULL) printf("%c\n", s->top->data);
}

void pushOnStack(stack *s, char value){
	node *ptr = (node*)malloc(sizeof(node));
	ptr->data = value;
	ptr->next = s->top;
	s->top = ptr;
}

int main(int argc, char *argv[])
{
	char expr[] = "((((())))))";
	stack myStack = createStack();
	printf("%lu\n", strlen(expr));
	for (int i = 0;i < strlen(expr);i++){
		if (expr[i] == '(') {
			pushOnStack(&myStack, '(');
		}
		else if (expr[i] == ')') {
			popOffStack(&myStack);
		}
	}
	if (myStack.top == NULL) {
		printf("Balanced\n");
	}
	else {
		printf("unbalanced\n");
	}
	return 0;
}
