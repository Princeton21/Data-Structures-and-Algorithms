/**
 * Queue implementation using pointer
 * @param <T>
 */

public class Queue<T> {
    static class Node<T> {
        T val;
        Node<T> next;

        public Node(T v) {
            val = v;
        }
    }

    private int size = 0;

    public int size() {
        return size;
    }

    private Node<T> front;
    private Node<T> rear;

    public void enqueue(T v) {
        size++;
        if (front == null) {
            front = new Node<>(v);
            rear = front;
            return;
        }
        rear.next = new Node<>(v);
        rear = rear.next;


    }

    public void add(T v) {
        enqueue(v);
    }

    public T poll() {
        return dequeue();
    }

    public T dequeue() {
        if (isEmpty()) {
            throw new IllegalArgumentException("Queue is empty");
        }
        Node<T> node = front;
        front = front.next;
        if (front == null) {
            rear = null;
        }
        size--;
        return node.val;
    }

    public T peek() {
        return front();
    }

    public T front() {
        if (isEmpty()) {
            throw new IllegalArgumentException("Queue is empty");
        }
        return front.val;
    }

    public T rear() {
        if (isEmpty()) {
            throw new IllegalArgumentException("Queue is empty");
        }
        return rear.val;
    }

    public boolean isEmpty() {
        return size == 0;
    }
    public static void main(String[]args){
        Queue<Integer>queue = new Queue<>();
        queue.enqueue(0);
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);
        System.out.println("queue size : "+queue.size());
        System.out.println("queue rear : "+queue.rear());
        System.out.println("queue front : "+queue.front());
        while (!queue.isEmpty()){
            int i = queue.poll();
            System.out.print("\t"+i);
        }
        System.out.println();
        System.out.println("queue size : "+queue.size());
    }


}
