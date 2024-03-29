/*
 * objective 1: implement stack
 *           2: implement push function
 *           3: implement display function
 *           4: implement pop function
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
void pop_stack(struct stack *stack); // pop element from stack

int main() {
    struct stack st;
    create_stack(&st);
    //------stack push--------------
    push_stack(&st, 10);
    push_stack(&st, 11);
    push_stack(&st, 12);
    push_stack(&st, 13);
    push_stack(&st, 14);
    push_stack(&st, 15);
    //------------------------------
    display_stack(st);
    //------stack pop---------------
    pop_stack(&st);
    //------------------------------
    printf("\nPOP\n");
    display_stack(st);
    return 0;
}

void create_stack(struct stack *stack){
    stack->size = 10; //sample size 10
    stack->top = -1; // stack is empty
    stack->pointer_to_stack_array = (int *)malloc(stack->size * sizeof(int)); //int pointer allocate memory
}

void display_stack(struct stack stack){
    for(int i=stack.top; i>=0; i--){
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

void pop_stack(struct stack *stack){
    if(stack->top == -1)
        printf("Stack Empty");
    else{
        stack->top--;
    }
}
