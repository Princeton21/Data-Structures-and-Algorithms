
/**
@Author Douly

Class reperesenting Doubly linked list creation,insertion,deletion and traversal
**/

public class DoublyLinkedList {

	public static void main(String[] args) {

		int[] input = new int[]{2,10,5,9};
		Node currentList = doublyLinkedListFromArray(input);
		System.out.println("Currently doubly linked list is");
		traverseDoublyLinkedList(currentList);

		currentList = deleteElementFromEndOfList(currentList);
		System.out.println("Deleting element from end of current list");
		traverseDoublyLinkedList(currentList);

		currentList = deleteElementFromBeginningOfList(currentList);
		System.out.println("Deleting element from start of current list");
		traverseDoublyLinkedList(currentList);

		currentList = insertElementAtBeginningOfList(currentList,6);
		System.out.println("Inserting 6 at beginning");
		traverseDoublyLinkedList(currentList);

		currentList = insertElementAtEndOfList(currentList,8);
		System.out.println("Inserting 8 at end");
		traverseDoublyLinkedList(currentList);

	}
	
	/**
	 Converts array of integers to a doubly Linked List and returns the head/initial node of linked list
	**/
	private static Node doublyLinkedListFromArray(int[] arr) {
		Node head = new Node(arr[0]);
		Node temp = new Node(arr[1]);

		head.setNext(temp);
		temp.setPrev(head);

		for(int i=2;i<arr.length;i++) {
		   Node currentNode = new Node(arr[i]);
		   currentNode.setPrev(temp);
		   temp.setNext(currentNode);
		   temp=currentNode;
		}

		return head;
	}

	/**
	Inserts an element at the starting of the doubly linked list
	**/
	private static Node insertElementAtBeginningOfList(Node head,int element) {
		Node newNode = new Node(element);

		if(head==null) 
			return newNode;
		else {
			head.setPrev(newNode);
			newNode.setNext(head);
			head = newNode;
		}
		return head;
	}

	/**
	Inserts an element at the end of the doubly linked list
	**/
	private static Node insertElementAtEndOfList(Node head,int element) {
		Node newNode = new Node(element);

		if(head==null) 
			return newNode;
		else {
			Node temp = head;
			while(temp.getNext()!=null) {
				temp = temp.getNext();
			}
			newNode.setPrev(temp);
			temp.setNext(newNode);

		}
		return head;
	}

	
	/**
	Deletes an element from the start of the doubly linked list
	**/
	private static Node deleteElementFromBeginningOfList(Node head) {

		if(head==null) 
			return null;
		else {
			Node temp = head.getNext();
			//temp is now the second element of the list
			head.setNext(null);
			if(temp!=null)
			temp.setPrev(null);
			head = temp;

		}
		return head;
	}

	/**
	Deletes an element from the end of the doubly linked list
	**/
	private static Node deleteElementFromEndOfList(Node head) {

		if(head==null) 
			return null;
		else {
			Node temp = head;
			while(temp.getNext()!=null && temp.getNext().getNext()!=null) {
				temp = temp.getNext();
			}
			//temp is now the second last element of the list
			if(temp.getNext()!=null)
			temp.getNext().setPrev(null);

			temp.setNext(null);

		}
		return head;
	}

	/**
	 Traverses a doubly linked list , starting from head node
	**/
	private static void traverseDoublyLinkedList(Node head) {
		if(head==null)
		return;

		Node temp = head;

		while(temp!=null) {
			System.out.print(temp.getData()+" ");
			temp=temp.getNext();
		}
		System.out.println("");
	}


	/**
	 Node class representing the node of linked list.
	**/
	public static class Node {
		
		private int data;
                private Node next;
		private Node prev;
                
                public Node(int value) {
			this.data = value;
			this.next = null;
			this.prev = null;
		}
		
		public int getData(){
			return this.data;
		}

		public Node getNext(){
			return this.next;
		}

		public void setNext(Node node){
			this.next = node;
		}

		public Node getPrev(){
			return this.prev;
		}

		public void setPrev(Node node){
			this.prev = node;
		}
		
	}
}
