#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) 
{
    struct Node* newNode = createNode(data);
    if (*head == NULL) 
    {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

void deleteNode(struct Node** head, int key) 
{
    if (*head == NULL)
    {
        return;
    }

    struct Node* temp = *head;
    while (temp != NULL && temp->data != key) 
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        return;
    }

    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        *head = temp->next;
    }

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

struct Node* search(struct Node* head, int data) 
{
    struct Node* current = head;
    while (current != NULL) 
    {
        if (current->data == data) 
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void printList(struct Node* head) 
{
    struct Node* temp = head;
    while (temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() 
{
    struct Node* head = NULL;
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);

    printf("Doubly linked list: ");
    printList(head);

    int searchData = 20;
    struct Node* result = search(head, searchData);
    if (result != NULL) 
    {
        printf("%d found in the list.\n", searchData);
    } 
    else 
    {
        printf("%d not found in the list.\n", searchData);
    }

    int deleteData = 20;
    deleteNode(&head, deleteData);
    printf("After deleting %d: ", deleteData);
    printList(head);

    return 0;
}
