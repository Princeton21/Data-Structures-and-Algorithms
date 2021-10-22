import java.util.ArrayList;

public class Main {
	public static void main(String[] args) {
		
		// Creating an object of Stack class
		// Declaring objects of Integer type
		stack<Integer> s = new stack<>(3);
		
		// Pushing elements to integer stack - stack
		// 101 -204 356
		s.push(101);
		s.push(-204);
		s.push(356);
		
		//Printing elements of stack
		//101 -204 356
		System.out.println(s.toString());
		
		//Reviewing top element
		//101
		System.out.println("Top element of stack: " + s.top());
		
		//pop element from the stack
		//356 is removed
		s.pop();
		
		//Printing elements of stack
		//101 -204
		System.out.println(s.toString());
	}
}

class stack<E>{
	ArrayList<E> arr;
	int top = -1;	// Default value of top variable when stack is empty
	int size;	// Variable to store size of array
	
	//Constructor of class
	stack(int size){
		this.size = size;
		this.arr = new ArrayList<E>(size);
	}
	
	// To push generic element into stack
	boolean push(E ele) {
		
		// Checking if array is full
		if(top+1 == size) {
			System.out.println("Stack Overflow");
			return false;
		}
		else {
			top++;
			if(arr.size() > top)
				arr.set(top, ele);	// Over-writing existing element
			else
				arr.add(ele);	// Creating new element
		}
		return true;
	}
	
	// To return topmost element of stack
	E top() {
		
		 // If stack is empty
		if(top == -1) {
			System.out.println("Stack Underflow");
			return null;
		}
		
		return arr.get(0);
	}
	
	// To delete last element of stack
	boolean pop() {
		if(top == -1) {
			System.out.println("Stack Underflow");
			return false;
		}
		
		top--;		// Delete the last element by decrementing the top
		return true;
	}
	
	// To check if stack is empty or not
	boolean empty() {
		if(top != -1)
			return false;
		return true;
	}
	
	@Override
	// To print the stack
	public String toString() {
		String ans = "";
		for(int i=0; i<top; i++)
			ans += String.valueOf(arr.get(i)) + " -> ";
		ans += String.valueOf(arr.get(top));
		return ans;
	}
}