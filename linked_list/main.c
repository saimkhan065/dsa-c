#include <stdio.h>
#include <stdlib.h>
/*
 * Objective : 1. create linked list struct
 * 2. create single linked list
 * 3. add node at end of list
 */

typedef struct node{
    int data;
    struct node* next;
} *Node;

void addNode(Node* head, int data);
void displayList(Node head);

int main() {
    /*
     * to add a node...
     * 1. need to maintain a ptr to first node (head)
     * 2. need a ptr that starts at head but can iterate(nodePtr)
     */
    Node head=NULL;
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    displayList(head);
    return 0;
}

void addNode(Node* head, int data){
    Node nodePtr = malloc(sizeof(Node));
    nodePtr->data = data;
    nodePtr->next=NULL;
    if (*head == NULL){
        *head = nodePtr;
        printf("Head was null. Creating first node.\n");
        printf("nodePtr->data: %d\n", nodePtr->data);
        printf("nodePtr->next: %p\n", nodePtr->next);
        return;
    }
    Node last = *head;
    while(last->next != NULL)
        last = last->next;
    last->next = nodePtr;
}
void displayList(Node head){
    Node temp = head;
    while (temp!=NULL){
        printf("\nData: %d Curr Addr: %p Next Addr: %p", temp->data, temp ,temp->next);
        temp=temp->next;
    }
}
