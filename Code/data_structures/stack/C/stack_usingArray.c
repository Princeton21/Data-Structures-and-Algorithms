#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// stack structure
struct Stack
{
    int top;
    unsigned capacity;
    int *arr;
};

//Stack creating function
struct Stack *createStack(unsigned capacity)
{
    struct Stack *mystack = (struct Stack *)malloc(sizeof(struct Stack));
    mystack->capacity = capacity;
    mystack->top = -1;
    mystack->arr = (int *)malloc(mystack->capacity * sizeof(int));
    return mystack;
}

//to check stack is full or not
int isFull(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

// to check stack is empty or not
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Push function
void push(struct Stack *stack, int item)
{
    if (isFull(stack)){
        printf("Stack is full\n");
        return;
    }
        
    stack->arr[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

// Pop Function
int pop(struct Stack *stack)
{
    if (isEmpty(stack)){
        printf("There is nothing to remove now-->Stack is empty ");
        return INT_MIN;
    }
    return stack->arr[stack->top--];
}

//peek function
int peek(struct Stack *stack)
{
    if (isEmpty(stack)){
        
        return INT_MIN;
    }
    return stack->arr[stack->top];
}


int main(){
    struct Stack *stack = createStack(2);

    // push operations
    push(stack, 15);
    push(stack, 20);
    push(stack, 25);

    //pop operations
    printf("%d popped from stack\n", pop(stack));
    printf("%d popped from stack\n", pop(stack));
    printf("%d popped from stack\n", pop(stack));
    printf("%d popped from stack\n", pop(stack));

    return 0;
}
