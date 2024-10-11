#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node * next;
} Node;

typedef Node * Queue;

Queue initQueue()
{
    Queue queue = (Queue)malloc(sizeof(Node));
    queue->data = 0;
    queue->next = NULL;
    return queue;
}

