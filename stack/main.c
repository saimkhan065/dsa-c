/*
 * objective 1: implement stack
 */
#include <stdio.h>
#include <stdlib.h>

struct stack{
    int top;
    int size;
    int *pointer_to_stack_array;
};
void create_stack(struct stack *stack); //initialise a stack
void display_stack(struct stack stack); //display stack
void push_stack(struct stack *stack, int element); // push an element in stack

int main() {
    printf("Hello, World!\n");
    return 0;
}

void create_stack(struct stack *stack){
    stack->size = 10; //sample size 10
    stack->top = -1; // stack is empty
    stack->pointer_to_stack_array = (int *)malloc(stack->size * sizeof(int)); //int pointer allocate memory
}

void display_stack(struct stack stack){
    for(int i=0; i>=0; i--){
        printf("%d\n", stack.pointer_to_stack_array[i]);
    }
}

void push_stack(struct stack *stack, int element){
    if(stack->top == stack->size-1){
        printf("Stack overflow");
    }else{
        stack->top++;
        stack->pointer_to_stack_array[stack->top] = element;
    }
}
