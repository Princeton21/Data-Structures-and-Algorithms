//program to print the reverse of a string using stack
#include<stdio.h>
typedef struct stack
{
    char data[100];
    int top;
}STACK;
//push function
void push(STACK *s, char ch)
{
    s->data[++(s->top)]=ch;
}
char pop(STACK *s)
{
    return s->data[(s->top)--];
}
void stringrev(char str[])
{
    STACK *s;
    s->top=-1;
    int i=0;
    while(str[i]!='\0') //pushing the original string
        push(s,str[i++]);
    char rev[100];
    i=0;
    while(s->top!=-1)   //creating the reversed string
        rev[i++]=pop(s);
    rev[i]='\0';
    printf("\nthe reversed string is\n%s\n",rev);   //printing the reversed string 
}
int main(void)
{
    char a[100],b[100];
    printf("\nenter the string\n");
    scanf("%[^\n]s",&a);
    stringrev(a);   //function call
}