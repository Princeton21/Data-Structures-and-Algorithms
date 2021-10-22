package online;

/**
 * Linked list ADT implementation
 * @param <T>
 */

public class LinkedList<T> {
    static class Node<T>{
        T val;
        Node<T>next;
        public Node(T v){
            val = v;
        }
    }
    private Node root;
    private int size = 0;
    public int size(){
        return size;
    }

    public void addLast(T v){
        if( root==null){
            size++;
            root = new Node(v);
            return;
        }
        Node c;
        for(c = root;c.next!=null;c=c.next);
        c.next = new Node(v);
        size++;
    }
    public void add(T v){
        addLast(v);
    }
    public void addFirst(T v){
        if( root ==null){
            size++;
            root =new Node(v);
            return;
        }
        Node c = new Node(v);
        c.next =root;
        root =c;
        size++;

    }
    public void add(int index,T v){
        if( index <0 || index > size) {
            throw new IllegalArgumentException("Invalid index");
        }
        Node<T>current = root;
        for(int i=0;i<index;i++){
            if( index==i){
                break;
            }
            if(current.next==null){
                break;
            }
            current  = current.next;
        }
        Node<T>nextNode = current.next;
        Node<T>node = new Node<>(v);
        current.next = node;
        node.next = nextNode;
        size++;
    }



    public boolean remove(T v){
        if( isEmpty()){
            throw new IllegalArgumentException("Linked List is empty");
        }
        Node<T> prev = null;
        Node<T> node ;
        for( node=root;node!=null;node=node.next){
            if( v.equals(node.val)){
                break;
            }
            prev = node;
        }

        if( node !=null) {
            if( prev!=null){
                prev.next = node.next;

            }
            else if(root==node){
                root = root.next;
            }
            node.next = null;
            size--;
            return true;
        }

        return false;
    }

    public boolean isEmpty(){
        return size ==0;
    }
    public T removeFirst(){
        if( isEmpty()){
            throw new IllegalArgumentException("Linked List is empty");
        }
        Node<T>node = root;
        root =root.next;
        size--;
        return node.val;
    }
    public T removeLast(){
        if( isEmpty()){
            throw new IllegalArgumentException("Lined List is empty");
        }
        Node<T>node;
        Node<T>prev =null;
        for(node=root;node.next!=null;node=node.next){
            prev = node;
        }
        if( prev !=null){
            prev.next = null;
        }
        else if( root == node){
            root = null;
        }
        size--;
        return node.val;

    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder("[ ");
        String join = "";
        for(Node<T>n =root;n!=null;n=n.next ){
            sb.append(join).append(n.val).append(" ");
            join=", ";
        }
        sb.append("]");
        return sb.toString();
    }
    public static void main(String[]args){
        LinkedList<Integer>linkedList = new LinkedList<>();
        linkedList.add(1);
        linkedList.add(2);
        linkedList.add(0);
        linkedList.add(5);
        linkedList.add(7);
        System.out.println("linked list size : "+linkedList.size());
        System.out.println("linked list values : "+linkedList );
        linkedList.remove(0);
        System.out.println("linked list values :"+linkedList);
        linkedList.remove(1);
        System.out.println("linked list values :"+linkedList);
        linkedList.add(1,6);
        System.out.println("linked list values :"+linkedList);
        linkedList.addFirst(-1);
        linkedList.addLast(10);
        System.out.println("linked list values :"+linkedList);
        System.out.println("linked list size  :"+linkedList.size());
        System.out.println("remove first : "+linkedList.removeFirst());
        System.out.println("remove last : "+linkedList.removeLast());
        System.out.println("linked list size : "+linkedList.size());

    }
}
