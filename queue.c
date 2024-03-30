#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct 
{
    int arr[MAX_SIZE];
    int front, rear;
} CircularQueue;

void initQueue(CircularQueue *q) 
{
    q->front = -1;
    q->rear = -1;
}

int isEmpty(CircularQueue *q) 
{
    return (q->front == -1 && q->rear == -1);
}

int isFull(CircularQueue *q) 
{
    return ((q->rear + 1) % MAX_SIZE == q->front);
}

void enqueue(CircularQueue *q, int value) 
{
    if (isFull(q)) 
    {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q))
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }
    q->arr[q->rear] = value;
}

int dequeue(CircularQueue *q) 
{
    if (isEmpty(q)) 
    {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = q->arr[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    return value;
}

int peek(CircularQueue *q) 
{
    if (isEmpty(q)) 
    {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->arr[q->front];
}

int main() 
{
    CircularQueue q;
    initQueue(&q);
    
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    
    printf("Front element: %d\n", peek(&q));
    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Front element after dequeue: %d\n", peek(&q));
    
    return 0;
}
