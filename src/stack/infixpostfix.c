// infix: a+b; postfix: ab+
// example x-y*z to post fix, first parenthesize it: (x-(y*z))
// (x-[yz*]) --> use [] to show that the given part has been converted
// xyz*-
// it is evaluated as:
// first go from x to z, then look at the first operator
// first operator is * and the operands are y and z so do y*z
// then the next operator is - and the operands are x and yz
// so do x - yz
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <malloc.h>
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

char peekTopValue(stack *s) {
  if (s->top == NULL) {
    return -1;
  }
  return s->top->data;
}

void pushOnStack(stack *s, char value){
  node *ptr = (node*)malloc(sizeof(node));
  ptr->data = value;
  ptr->next = s->top;
  s->top = ptr;
}

int isEmpty(stack *s) {
  if (s->top == NULL)
    return 1;
  else return 0;
}

int returnPriority(char c) {
  if(c == '*' || c == '/') return 2;
  else if (c == '+' || c == '-') return 1;
  else printf("you sent: %c", c); return 0;
}

int isVariable(char c) {
  if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return 1;
  else return 0;
}
int main() {
  stack myStack = createStack();
  char expr[] = "a+b*c";
  char pos[strlen(expr) + 1];
  size_t i = 0; // infix counter
  size_t j = 0; // postfix counter

  while (expr[i] != '\0') {
    if (isVariable(expr[i])) {
      pos[j++] = expr[i++];
    } else {
      while (!isEmpty(&myStack) && returnPriority(peekTopValue(&myStack)) >= returnPriority(expr[i])) {
        pos[j++] = peekTopValue(&myStack);
        popOffStack(&myStack);
      }
      pushOnStack(&myStack, expr[i]);
      i++;
    }
  }

  while (!isEmpty(&myStack)) {
    pos[j++] = peekTopValue(&myStack);
    popOffStack(&myStack);
  }
  
  pos[j] = '\0';
  printf("%s\n", pos);
  
  return 0;
}
