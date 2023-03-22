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
void enqueue(struct queue *q ,int element);
void dequeue(struct queue *q);
void display(struct queue q);

int main() {
    struct queue q;
    create_queue(&q, 10);
    //-------enqueue---------
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    display(q);
    //-------enqueue---------

    //-------dequeue---------
    printf("--dequeue--\n");
    dequeue(&q);
    dequeue(&q);
    display(q);
    //-------dequeue---------
    return 0;
}

void create_queue(struct queue *q, int size){
    q->size = size;
    q->front = -1;
    q->rear = -1;
    q->pointer_to_array = (int *) malloc(q->size * sizeof(int));
}

void enqueue(struct queue *q, int element){
    if (q->rear == q->size-1 )
        printf("Overflow. Queue Full.");
    else{
        q->rear++;
        q->pointer_to_array[q->rear] = element;
    }
}

void dequeue(struct queue *q){
    if (q->front == q->rear)
        printf("queue empty\n");
    else{
        q->front++;
    }
}

void display(struct queue q){
    for(int i = q.front+1; i<= q.rear; i++){
        printf("%d\n", q.pointer_to_array[i]);
    }
}
