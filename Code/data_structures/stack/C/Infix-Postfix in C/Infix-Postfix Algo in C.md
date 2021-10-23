
# Infix To Postfix conversion using Stack in C

This tutorial implements one of the application of stacks which is Infix To Postfix conversion using Stack in C.

The readme file consists steps required to fulfill the application of Infix to Postfix conversion.

This also includes the code in C required for implementing this algorithm.

But before we move on further , a basic knowledge of concets like Stacks and Infix to Postfix Expression is required,

# Stacks
Stacks are Linear Data Structures which can be implemented in C by using two ways: Arrays and Linked Lists.

* A stack is shielded at one end.
* Data can be inserted or removed from only one end.
* The insertion operation in stack is called as **PUSH.**
* If we are removing any element from a stack it is called as **POP.**


- If we want to push an element in stack,we need to mention what element needs to be pushed.
- But to pop an element,the first element gets removed by default.

## Top of the Stack:
**top** is a variable whose initial value is always -1.
When top=-1,stack is always empty.

(we increment the value of top each and everytime we push an element into stack)
![image](https://drive.google.com/uc?id=1RXhgEzKNNrcZq1_UH9hlW-gn_uUt2NOi)
If we need to access an element in a stack,we need to pop all top elements.

Stack follows **Last-In-First-Out[LIFO]** principle. Which means that the element
which is pushed last in the stack will be the first one to be popped out.

* **Stack Overflow:** Stack is already full and we can't push any element in it.
* **Stack Underflow:** The stack is empty and we can't pop any element from it.

# Infix to Postfix expression:
Before moving further,it is important to know how manual conversion of an Infix to Postfix Expression takes place:

- Consider the expression given below:
``` ((a+b)*c)  ```
- The main idea here is to put the operator after the element.
- Parenthesis gets the highest priority here,therefore first we will perform operation on (a+b).
``` (ab+ *c)```
- **ab+** here now becomes an individual element. Perform postfix operation further on other element.
``` ab+ c*```
- This is the postfix expression we get.Remove the brackets as well.

*If we consider other expression :* ```(a*b/c^e)```

The postfix expression for this would come as ```ab* ce^```

(Keeping the priority order in mind,the exponential always gets highest priority.)

# Algorithm for Infix to Postfix Expression: 
**I.** Initialize an  empty stack.

**II.** Push "("onto stack,and add")" to the end of input string.

**III.** Scan the input string character by character left to right.

**IV.** If an operand is encountered, add it to P(Output String).

**V.** If an opening(left) parenthesis '(' is encountered push it to stack.

**VI.** If an operator is encountered then if the top of stack is opening parenthesis, push it to the stack.

*If operator has higher or same priority than the current operator, pop the operator from the stack and add it output string, repeat for every operator in the stack.*

*Push the current operator on to the stack.*

**VII.** If it is a closing parenthesis, pop the operator from stack  and add them to an output string until an opening parenthesis is encountered.Pop and discard the opening parenthesis.

**VIII.** If there is more input,go to step III.

*Refer the code as well.*