#include <stdio.h>
#include <stdlib.h>
typedef struct stack{
	int size;
	int top;
	int *arr;
}stack;

stack createStack(int size){
	int *ptr = (int*)malloc(size * sizeof(int));
	stack s = {size, -1, ptr}; // -1 because the first element comes at 0
	return s;
}

int isEmpty(stack *s){
	if (s->top == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

int isFull(stack *s){
	if (s->top == s->size-1) {
		return 1;
	}
	else {
		return 0;
	}
}

void pushOnstack(stack *s, int value){
	if (isFull(s)) {
		printf("stack full\n");
		exit(1);
	}
	s->top++; // -1 to 0 for first element
	s->arr[s->top] = value;
}

int popOffStack(stack *s){
	if (isEmpty(s)) {
		printf("stack empty\n");
		exit(1);
	}
	int value = s->arr[s->top];
	s->top--;
	return value;
}

void printTopValue(stack *s){
	printf("top value of stack is: %d\n", s->arr[s->top]);
}

void freeStack(stack *s){
	free(s->arr);
}


int seek(stack *s){
	return s->arr[s->top];
}

int main(int argc, char *argv[])
{
	stack myStack = createStack(2);
	printf("my stack size is: %d\n", myStack.size);
	printf("is my stack empty? %d\n", isEmpty(&myStack));
	pushOnstack(&myStack, 69);
	printTopValue(&myStack);
	printf("is my stack empty? %d\n", isEmpty(&myStack));
	pushOnstack(&myStack, 67);
	printf("is my stack full? %d\n", isFull(&myStack));
	printTopValue(&myStack);
	printf("value just popped: %d\n", popOffStack(&myStack));
	printTopValue(&myStack);
	printf("is my stack full? %d\n", isFull(&myStack));
	printf("top value without removing: %d\n", seek(&myStack));
	pushOnstack(&myStack, 99);
	printf("top value without removing: %d\n", seek(&myStack));
	freeStack(&myStack);
	return 0;
}
