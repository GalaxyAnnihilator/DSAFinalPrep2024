#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 100

typedef struct {
    int capacity;
    int front, back;
    int *data;
} Queue;

Queue* init(int N) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = 0;
    q->back = 0;
    q->capacity = N;
    q->data = (int*)malloc(N * sizeof(int));  // Allocate memory for N elements
    return q;
}

int isEmpty(Queue *q) {
    return (q->front == q->back);
}

int length(Queue *q) {
    return (q->back - q->front + q->capacity) % q->capacity;
}

int isFull(Queue *q) {
    return (length(q) == q->capacity - 1);  // Full when there's no space left
}

int enqueue(Queue *q, int newValue) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return 0;
    }
    q->data[q->back] = newValue;
    q->back = (q->back + 1) % q->capacity;
    return 1;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;  // Indicate an error
    }
    int val = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    return val;
}

void freeQueue(Queue *q) {
    free(q->data);
    free(q);
}

int main() {
    // Example usage of the queue
    Queue* q = init(CAPACITY);

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);

    printf("Dequeued: %d\n", dequeue(q));  // Should print 1
    printf("Dequeued: %d\n", dequeue(q));  // Should print 2

    enqueue(q, 4);
    enqueue(q, 5);

    printf("Dequeued: %d\n", dequeue(q));  // Should print 3
    printf("Dequeued: %d\n", dequeue(q));  // Should print 4

    freeQueue(q);

    return 0;
}
