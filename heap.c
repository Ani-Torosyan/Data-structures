#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

struct MaxHeap 
{
    int heap[MAX_HEAP_SIZE];
    int size;
};

void maxHeapify(struct MaxHeap *heap, int index) 
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->heap[left] > heap->heap[largest])
    {
        largest = left;
    }

    if (right < heap->size && heap->heap[right] > heap->heap[largest])
    {
        largest = right;
    }

    if (largest != index) 
    {
        int temp = heap->heap[index];
        heap->heap[index] = heap->heap[largest];
        heap->heap[largest] = temp;
        maxHeapify(heap, largest);
    }
}

void insertMaxHeap(struct MaxHeap *heap, int key) 
{
    if (heap->size >= MAX_HEAP_SIZE) 
    {
        printf("Heap overflow\n");
        return;
    }

    int index = heap->size++;
    heap->heap[index] = key;

    while (index != 0 && heap->heap[(index - 1) / 2] < heap->heap[index]) 
    {
        int temp = heap->heap[index];
        heap->heap[index] = heap->heap[(index - 1) / 2];
        heap->heap[(index - 1) / 2] = temp;
        index = (index - 1) / 2;
    }
}

int extractMax(struct MaxHeap *heap) 
{
    if (heap->size <= 0) 
    {
        printf("Heap underflow\n");
        return -1;
    }

    int max = heap->heap[0];
    heap->heap[0] = heap->heap[--heap->size];
    maxHeapify(heap, 0);

    return max;
}

int peekMax(struct MaxHeap *heap) 
{
    if (heap->size <= 0) 
    {
        printf("Heap is empty\n");
        return -1;
    }
    return heap->heap[0];
}

void increaseKey(struct MaxHeap *heap, int index, int newKey) 
{
    if (newKey < heap->heap[index]) 
    {
        printf("New key is smaller than the current key\n");
        return;
    }

    heap->heap[index] = newKey;

    while (index != 0 && heap->heap[(index - 1) / 2] < heap->heap[index]) 
    {
        int temp = heap->heap[index];
        heap->heap[index] = heap->heap[(index - 1) / 2];
        heap->heap[(index - 1) / 2] = temp;
        index = (index - 1) / 2;
    }
}

int main() 
{
    struct MaxHeap heap;
    heap.size = 0;

    insertMaxHeap(&heap, 10);
    insertMaxHeap(&heap, 20);
    insertMaxHeap(&heap, 15);

    printf("Max element: %d\n", peekMax(&heap));

    extractMax(&heap);
    printf("Max element: %d\n", peekMax(&heap));

    increaseKey(&heap, 1, 25);
    printf("Max element: %d\n", peekMax(&heap));

    insertMaxHeap(&heap, 30);
    printf("Max element: %d\n", peekMax(&heap));

    return 0;
}