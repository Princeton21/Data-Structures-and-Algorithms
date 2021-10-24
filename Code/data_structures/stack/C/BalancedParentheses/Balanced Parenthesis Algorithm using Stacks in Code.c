//Code for implementing Balanced Parenthesis Algorithm using Stacks in Code
#include<stdio.h>
#include<string.h>
//parenthesis matching
char stack[100]; //declaring the character stack
int top=-1,i;
int size=50;
char string[120];
void push (char elem)
{
    if(size==top+1)
    {
        printf("Stack Overflow\n"); //checking if the stack is already full or not
    }
    else
    {
        top++;
        stack[top]=elem;
        printf("Pushed %c\n",elem);
    }
    
}
void pop()
{
    if(top==-1)
    {
        printf("Stack Underflow\n"); //checking whether the stack is empty or not
    }
    else
    {
        printf("Popped %c\n",stack[top]);
        top--;
    }
}
void check()
{
    for(i=0;i<strlen(string);i++)
    {
        if(string[i]=='(')
        {
            push(string[i]);
        }
        else if(string[i]==')')
        {
            pop();
        }
    }
    if(top==-1)
    {
        printf("Balanced Parenthesis\n"); //if the stack is empty after performing the push and pop operations,the expression is balanced
    }
    else
    {
        printf("Unbalanced Parenthesis\n");
    }
}
void main()
{
    printf("Enter the expression\n");
    scanf("%s",string);
    check(string);
}









