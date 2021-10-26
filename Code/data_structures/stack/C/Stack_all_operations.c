/**
  * Name - Vivek Kumar Singh
  * Email - singhvivekkumar309@gmail.com
  * College's name - B.P Mandal College of Engneering, Madhepura
  */


#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Stack {
	int top;
	int capacity;
	int *array;
};

struct Stack *createStack(int capacity) {
	struct Stack *S = malloc(sizeof(struct Stack));
	if(!S) {
		return NULL ;
	}
	S->capacity = capacity;
	S->top = -1;
	S->array = malloc(S->capacity * sizeof(int));
	if(!S->array) {
		return NULL;
	}
	return S;
}

int isEmpty(struct Stack *S) {
	return (S->top == -1);	// if the condition is true then 1 is returned else 0 is returned
}

int size(struct Stack *S){
	return (S->top + 1);
}

int isFull(struct Stack *S) {
	// if the condition is true then 1 is returned else 0 is returned
	return (S->top == S->capacity -1);
}

void push(struct Stack *S, int data) {
	/* S->top == capacity -1 indicates that the stack is full */
	if(isFull(S)) {
		printf("Stack Overflow \n");
	}
	else /* Increasing the 'top' by 1 and storing the value at 'top' position */ 
	{
		S->array[++S->top] = data;
	}
}

int pop(struct Stack *S) {
	/* S->top == -1 indicates empty stack*/
	if(isEmpty(S)) {
		printf("Stack is Empty \n");
		return INT_MIN;
	}
	else { /* Removing element from 'top' of the array and reducing 'top' by 1 */ 
		return (S->array[S->top-1]);
	}
}

int peek(struct Stack *S) {
	/* S->top == -1 indicates empty stack */
	if(isEmpty(S)) {
		printf("Stack Empty ");
		return INT_MIN;
	}
	else {
		return (S->array[S->top]);
	}
}

void deleteStack(struct Stack *S) {
	if(S) {
		if(S->array){
			free(S->array);
		}
		free(S);
	}
}

int main() {
	
	int i=0 , capacity = 15;
	//create a stack of capacity 15
	struct Stack *stk = createStack(capacity);
	for( i=0; i<=capacity; i++) {
		push(stk,i);
	}
	
	printf("Top element is %d\n", peek(stk));
	printf("Stack size is %d\n", size(stk));
	for (i=0; i<=capacity; i++) {
		printf("Popped elements is %d\n", pop(stk));
	}
	
	if(isEmpty(stk)) {
		printf("Stack is empty ");
	}
	else {
		printf("Stack is not empty");
	}
	deleteStack(stk);
	
	return 0;	
}

