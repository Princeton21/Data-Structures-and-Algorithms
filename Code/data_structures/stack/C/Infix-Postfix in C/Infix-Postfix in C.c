//infix expression to a postfix expression
#include<stdio.h>
#include<string.h>
#include<ctype.h>
char stack[100];
int top=-1,i;
int size=50;
void push(char item)
{
  //stack overflow
  if(size==top+1)
  {
      printf("Stack Overflow\n");
  }
  else
  {
      top++;
      stack[top]=item;
  }
}
char pop()
{
    if(top==-1)
    printf("Stack Underflow\n");
    else
    {
        return stack[top--];
    }
}
int precedence(char ope)
{
    switch(ope)
    {
        case '^':
        return 3;
        break;
        
        case '*':
        case '/':
        return 2;
        break;
        
        case '+':
        case '-':
        return 1;
        break;
        
        default:
        return 0;
    }
}
int main()
{
   char input[123],output[120];
   int j=-1;
   char temp;
   printf("Enter the infix expression\n");
   scanf("%s",input);
   push('(');
   strcat(input,")");
   for(i=0;i<strlen(input);i++)
   {
       if(isalpha(input[i]))
       {
           output[++j]=input[i];
       }
       else if(input[i]=='(')
       {
           push(input[i]);
       }
       else if(input[i]=='^' || input[i]=='+' || input[i]=='-' || input[i]=='/' || input[i]=='*')
       {
           char temp=pop();
           if (temp=='(')
           {
               push(temp);
               push(input[i]);
           }
           else if(precedence(temp)>=precedence(input[i]))
           {
               output[++j]=temp;
               push(input[i]);
           }
           else if(input[i]==')')
           {
               temp=pop();
               while(temp!='(')
               {
                   output[++j]=temp;
                   temp=pop();
               }
           }
       }
   }
   printf("The postfix expression is %s\n",output);
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
}
