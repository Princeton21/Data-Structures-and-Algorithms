
# Balanced Parenthesis Algorithm using Stacks in C

Balanced Parenthesis Algorithm, is one of the applications of Stack.

In this tutorial we will see the steps for implementing this algorithm and the code as well.

## Main Approach:
This algorithm will be implemented by checking the number of Parenthesis. 
If it turns out to be 0;then it is a balanced parenthesis.

The basic idea over here is to check whether the number of opening parenthesis is equal to the number of closing parenthesis.

If we refer this problem with respect to stack,if there is an opening parenthesis,we push it to the stack
whereas if there is a closing parenthesis;we pop it out from the stack.

## Steps:
- Firstly,we will store the string in the form of char array and 
  traverse the array character by character.
- Creating a stack element.
- If an opening parenthesis is encountered,we will push it into the stack.
- If we encounter any operator or operand or something else apart from parenthesis,ignore it.
- If we come across a closing parenthesis,we will pop the top element from the stack.
- If the stack is empty after traversing the whole string;then it means that it is balanced parenthesis.

*Refer the image below for a better understanding:*
![image](https://drive.google.com/uc?id=1sTQMjKdggOEA67e46vFrChd1y11I1xm_)

*The steps are implemented in the code.*