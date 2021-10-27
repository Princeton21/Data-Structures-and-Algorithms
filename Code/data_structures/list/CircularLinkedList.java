
/**
@Author Douly

Traverses a circular linked list
**/

public class CircularLinkedList {

	public static void main(String[] args) {
    
		int[] input = new int[]{1,2,3,4,5,6};
		Node linkedList = circularLinkedListFromArray(input);
		traverseCircularList(linkedList);

	}
	
	/**
	 Converts array of integer to a circular Linked List and returns the head/initial node of linked list
	**/
	private static Node circularLinkedListFromArray(int[] arr) {
		int decimalValue = 0;
		Node head = new Node(arr[0]);
		Node temp = head;
		for(int i=1;i<arr.length;i++) {
		   Node currentNode = new Node(arr[i]);
		   temp.setNext(currentNode);
		   temp=currentNode;
		}
		temp.setNext(head);
		return head;
	}

	/**
	 Traverses a circular linked list , starting from head node
	**/
	private static void traverseCircularList(Node head) {
		if(head==null)
		return;

		System.out.print(head.getData()+" ");
		Node temp = head.getNext();

		while(temp!=head) {
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
                
                public Node(int value) {
			this.data = value;
			this.next = null;
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
		
	}
}
