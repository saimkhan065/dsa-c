
#include <stdio.h>
#include <stdlib.h>




typedef struct Node{
    int data;
    struct Node *ptrNextNode;
}Node, *NodePtr;

NodePtr createNode(int element);
NodePtr addNode(int element);
void displayNode(NodePtr nodePtr);

int main() {
    int listSize;
    NodePtr firstNode, secondNode, thirdNode;
    firstNode = createNode(10);
    secondNode = createNode(20);
    firstNode->ptrNextNode = secondNode;
    thirdNode = createNode(30);
    secondNode->ptrNextNode = thirdNode;

    displayNode(firstNode);
    displayNode(secondNode);
    displayNode(thirdNode);
    return 0;
}

NodePtr createNode(int element){
   NodePtr ptr;
    ptr = (NodePtr) malloc(sizeof (Node));
    ptr->data = element;
    ptr->ptrNextNode = NULL;
    return ptr;
}

void displayNode(NodePtr nodePtr){
    printf("Data at Node: %d\n", nodePtr->data);
    printf("Current Addr: %p\n", nodePtr);
    printf("Next Addr: %p\n", nodePtr->ptrNextNode);
}

NodePtr addNode(int element){
    NodePtr ptr;
    ptr = (NodePtr) malloc(sizeof (Node));
    ptr->data = element;
    ptr->ptrNextNode = NULL;
    return ptr;
}