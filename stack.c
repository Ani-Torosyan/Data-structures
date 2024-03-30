#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct 
{
    int arr[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s) 
{
    s->top = -1;
}

void push(Stack *s, int value) 
{
    if (s->top == MAX_SIZE - 1) 
    {
        printf("Stack overflow!\n");
        return;
    }
    s->arr[++(s->top)] = value;
}

int pop(Stack *s) 
{
    if (s->top == -1) 
    {
        printf("Stack underflow!\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

int top(Stack *s) 
{
    if (s->top == -1) 
    {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->arr[s->top];
}

int main() 
{
    Stack s;
    initStack(&s);
    
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    
    printf("Top element: %d\n", top(&s));
    printf("Popped element: %d\n", pop(&s));
    printf("Top element after pop: %d\n", top(&s));
    
    return 0;
}
