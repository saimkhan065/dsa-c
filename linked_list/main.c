/*
 * Objective: 1. implement linked list
 *            2. display linked list
 *            3. to be continued - add comments as I understand this concept clearly.
 */
#include <stdio.h>
#include <stdlib.h>

struct node {
    int element;
    struct node *next_node_pointer;
}*first_node_pointer=NULL;

void create_node(int a[], int n);
void display_linked_list(struct node *p);


int main() {
    int a[] = {1, 2, 3, 4, 5};
    create_node(a, 5);
    display_linked_list(first_node_pointer);
    return 0;
}

void create_node(int a[], int n){
    struct node *temporary_node_pointer, *last_node_pointer;
    first_node_pointer = (struct node *) malloc(sizeof(struct node));
    first_node_pointer->element = a[0];
    first_node_pointer->next_node_pointer = NULL;
    last_node_pointer = first_node_pointer;

    for(int i=1; i<n; i++){
        temporary_node_pointer = (struct node *)malloc(sizeof(struct node));
        temporary_node_pointer->element = a[i];
        temporary_node_pointer->next_node_pointer = NULL;
        last_node_pointer->next_node_pointer = temporary_node_pointer;
        last_node_pointer = temporary_node_pointer;
    }
}

void display_linked_list(struct node *p){
    while(p){
        printf("%d\t", p->element);
        p=p->next_node_pointer;
    }
}
