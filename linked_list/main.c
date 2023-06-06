#include <stdio.h>
#include <stdlib.h>
/*
 * Objective : 1. create linked list struct
 * 2. create single linked list
 * 3. add node at end of list
 */

typedef struct node{
    int data;
    struct node* next; // pointer to a struct node data type
}*NodePtr;

void addNodeAtEnd(NodePtr *head, int data);
void printList(NodePtr head);

int main() {

    NodePtr head = NULL;
    addNodeAtEnd(&head, 10);
    addNodeAtEnd(&head, 20);
    addNodeAtEnd(&head, 30);
    addNodeAtEnd(&head, 40);
    addNodeAtEnd(&head, 50);
    printList(head);
    free(head);
    return 0;
}

void addNodeAtEnd(NodePtr *head, int data){
    NodePtr newNode = malloc(sizeof(NodePtr));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL){
        *head = newNode;
        return;
    }
    NodePtr lastNode = *head;
    while(lastNode->next != NULL)
        lastNode = lastNode->next;
    lastNode->next = newNode;
}

void printList(NodePtr head){
    int count = 1;
    while(head!=NULL){
        printf("Node: %d Value: %d Current: %p Next: %p\n",count, head->data, head, head->next);
        head = head->next;
        count++;
    }
}