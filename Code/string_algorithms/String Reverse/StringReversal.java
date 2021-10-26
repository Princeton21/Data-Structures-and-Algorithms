/**
@Author Douly

Program to reverse a string using stack
**/
import java.util.Stack;

public class StringReversal {

	public static void main(String[] args) {
		String inputString = "HelloJavaIsBeautiful";
		System.out.println(inputString);
		Stack inputStack = getStackFromInputString(inputString);
		String reversedString = reverseStringUsingStack(inputStack);
		System.out.println(reversedString);
	}

	/**
	Constructs character Stack using the input String
	**/
	private static Stack getStackFromInputString(String str) {
		Stack<Character> charStack = new Stack();  

		for(int i=0;i<str.length();i++) {
			charStack.push(str.charAt(i));
		}
		return charStack;
	}

	/**
	Reverses the string using stack by popping the characters from stack 
	and appending them in String
	**/
	private static String reverseStringUsingStack(Stack charStack) {
		
		StringBuilder reversed = new StringBuilder();
		while(!charStack.empty()){
			reversed.append(charStack.pop());
		}
		return reversed.toString();
		
	}


}
