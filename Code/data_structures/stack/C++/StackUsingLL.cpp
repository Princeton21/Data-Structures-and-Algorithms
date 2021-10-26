#include <iostream>
using namespace std;

template <typename T>
class Node {
	public :
		T data;
		Node<T> *next;
	
		Node(T val){
			data = val;
			next = NULL;
		}
};

template <typename T>
class StackUsingLL {
	Node<T> *head;
	int size;
	
	public :
		StackUsingLL(){
			head = NULL;
			size = 0;
		}
		
		int getSize(){
			return size;
		}
		
		bool isEmpty(){
			return size==0;
		}
		
		void push(T val){
			Node<T> *newNode = new Node<T>(val);
			newNode->next = head;
			head = newNode;
			size++;
		}
		
		T pop(){
			if (head == NULL){
				return 0;
			}
			T ans = head->data;
			Node<T> *temp = head;
			head = head->next;
			delete temp;
			size--;
			return ans;
		}
		
		T top(){
			if (head == NULL){
				return 0;
			}
			return head->data;
		}
};

int main(){
	StackUsingLL<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	
	cout<<"Top element :"<<s.top()<<endl;
	
	cout<<"Popped element :"<<s.pop()<<endl;
	cout<<"Popped element :"<<s.pop()<<endl;
	
	cout<<"Empty or not :"<<s.isEmpty()<<endl;
	
	cout<<"Size :"<<s.getSize()<<endl;
}