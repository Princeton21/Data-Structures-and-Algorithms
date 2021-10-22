/**
 * Stack using pointer 
 * @param <T>
 */
public class Stack<T> {
    static class Node<T> {
        T val;
        Node next;

        public Node(T v) {
            val = v;
        }

        @Override
        public String toString() {
            return val +"";
        }
    }

    private Node<T> root;
    private int size = 0;

    public int size() {
        return size;
    }

    public void push(T v) {
        Node<T> node = new Node(v);
        node.next = root;
        root = node;
        size++;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public T pop() {
        if (isEmpty()) {
            throw new IllegalArgumentException("Stack is empty ");
        }
        Node<T> node = root;
        root = root.next;
        size--;
        return node.val;
    }
    public static void main(String[]args){
        Stack<Integer>stack = new Stack<>();
        stack.push(1);
        stack.push(2);
        stack.push(3);
        System.out.println("size : "+stack.size());
        System.out.println("is empty : "+stack.isEmpty());
        System.out.println("stack elements :");
        while (!stack.isEmpty()){
            int v = stack.pop();
            System.out.print("\t"+v);

        }
        System.out.println();
        System.out.println(" stack is empty : "+stack.isEmpty());
    }

}
