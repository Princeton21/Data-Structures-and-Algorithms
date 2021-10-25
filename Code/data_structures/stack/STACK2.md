# STACK
#### INTRODUCTION
Stack is a linear data structure that follows a particular order in which the operations are performed. The order may be LIFO(Last In First Out) or FILO(First In Last Out).

Mainly the following three basic operations are performed in the stack:

-   **Push:** Adds an item in the stack. If the stack is full, then it is said to be an Overflow condition.
-   **Pop:**  Removes an item from the stack. The items are popped in the reversed order in which they are pushed. If the stack is empty, then it is said to be an Underflow condition.
-   **Peek or Top:**  Returns the top element of the stack.
-   **isEmpty:** Returns true if the stack is empty, else false.

#### REAL LIFE EXAMPLES OF STACK  
There are many real-life examples of a stack. Consider the simple example of plates stacked over one another in a canteen. The plate which is at the top is the first one to be removed, i.e. the plate which has been placed at the bottommost position remains in the stack for the longest period of time. So, it can be simply seen to follow the LIFO/FILO order.

#### Time Complexities of operations on stack:
push(), pop(), isEmpty() and peek() all take O(1) time. We do not run any loop in any of these operations.

    #include <bits/stdc++.h>
    
    using namespace std;
    
    #define MAX 1000
    
    class Stack {
    	int top;
    
    public:
    	int a[MAX]; // Maximum size of Stack
    
    	Stack() { top = -1; }
    	bool push(int x);
    	int pop();
    	int peek();
    	bool isEmpty();
    };
    
    bool Stack::push(int x)
    {
    	if (top >= (MAX - 1)) {
    		cout << "Stack Overflow";
    		return false;
    	}
    	else {
    		a[++top] = x;
    		cout << x << " pushed into stack\n";
    		return true;
    	}
    }
    
    int Stack::pop()
    {
    	if (top < 0) {
    		cout << "Stack Underflow";
    		return 0;
    	}
    	else {
    		int x = a[top--];
    		return x;
    	}
    }
    int Stack::peek()
    {
    	if (top < 0) {
    		cout << "Stack is Empty";
    		return 0;
    	}
    	else {
    		int x = a[top];
    		return x;
    	}
    }
    
    bool Stack::isEmpty()
    {
    	return (top < 0);
    }
    
    // Driver program to test above functions
    int main()
    {
    	class Stack s;
    	s.push(10);
    	s.push(20);
    	s.push(30);
    	cout << s.pop() << " Popped from stack\n";
    	//print all elements in stack :
    	cout<<"Elements present in stack : ";
    	while(!s.isEmpty())
    	{
    		// print top element in stack
    		cout<<s.peek()<<" ";
    		// remove top element in stack
    		s.pop();
    	}
    
    	return 0;
    }

#### OUTPUT
10 pushed into stack
20 pushed into stack
30 pushed into stack
30 Popped from stack
Top element is : 20
Elements present in stack : 20 10

