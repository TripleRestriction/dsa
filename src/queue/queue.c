// stack works on the concept of first in last out
// queue is like irl queue, first in first out
// this one is a circular queue, because that is the only one that works with arrays
#include <stdio.h>
#include <stdlib.h>
typedef struct queue {
    int count;
    int size;
    int frontIndex;
    int backIndex;
    int *arrayPtr;
} queue;

queue createQueue(int size)
{
    int *ptr = (int *)malloc(sizeof(int) * size);
    queue newQueue = {0, size, -1, -1, ptr};
    return newQueue;
}

void insert(queue *q, int value)
{
    if (q->count == q->size) {
        printf("full\n");
        exit(1);
    }
    q->backIndex = (q->backIndex + 1) % q->size; // modulo to wrap it back
    q->arrayPtr[q->backIndex] = value;
    if (q->count == 0) {
	q->frontIndex = q->backIndex;
    }
    q->count++;
}

int removeFirst(queue *q)
{
    if (q->count == 0) {
        printf("empty!\n");
	exit(1);
    }
    int front = q->arrayPtr[q->frontIndex];
    q->frontIndex = (q->frontIndex + 1)%q->size; // wrap it back
    q->count--;
    return front;
}

int frontValue(queue *q)
{
    if (q->count == 0) {
        printf("cant read front value cuz empty!\n");
	exit(1);
    }
    return q->arrayPtr[q->frontIndex];
}

int backValue(queue *q)
{
    if (q->count == 0) {
        printf("cant read back value cuz empty!\n");
        exit(1);
    }
    return q->arrayPtr[q->backIndex];
}

int main()
{
    queue myQueue = createQueue(4);
    insert(&myQueue, 10);
    insert(&myQueue, 20);
    insert(&myQueue, 30);
    printf("%d\n", removeFirst(&myQueue));
    printf("%d\n", removeFirst(&myQueue));
    insert(&myQueue, 40);
    insert(&myQueue, 41);
    printf("la %d\n", removeFirst(&myQueue));
    insert(&myQueue, 42);
    printf("la %d\n", removeFirst(&myQueue));
    printf("la %d\n", removeFirst(&myQueue));
    printf("la %d\n", removeFirst(&myQueue));
}
