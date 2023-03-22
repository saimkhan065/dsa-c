/*
 * Objective: 1. implement queue
 */
#include <stdio.h>
#include <stdlib.h>

struct queue{
    int size;
    int *pointer_to_array;
    int front;
    int rear;
};

void create_queue(struct queue *q, int size);

int main() {
    struct queue q;
    create_queue(&q, 10);
    return 0;
}

void create_queue(struct queue *q, int size){
    q->size = size;
    q->front = -1;
    q->rear = -1;
    q->pointer_to_array = (int *) malloc(q->size * sizeof(int));
    printf("function run success!"); // check to see if any error rn
}
