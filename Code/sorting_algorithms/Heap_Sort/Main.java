package Heap_Sort;

class Main {
    public static void main(String[] args){
        int[] arr = {2,6,10,3,11,15,23};
        Heap ob = new Heap();
        ob.heapSort(arr);
        ob.display(arr);
    }
}
