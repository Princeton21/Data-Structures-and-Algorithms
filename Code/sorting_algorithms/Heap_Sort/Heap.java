package Heap_Sort;

public class Heap {
    public void heapSort(int[] arr)
    {
        int temp;

        for (int i = arr.length / 2 - 1; i >= 0; i--)
        {
            cheapish(arr, arr.length, i);
        }

        for (int i = arr.length - 1; i > 0; i--)
        {
            temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            cheapish(arr, i, 0);
        }
    }

    public void cheapish(int[] arr, int n, int i)
    {
        int MAX = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int temp;

        if (left < n && arr[left] > arr[MAX])
        {
            MAX = left;
        }

        if (right < n && arr[right] > arr[MAX])
        {
            MAX = right;
        }

        if (MAX != i)
        {
            temp = arr[i];
            arr[i] = arr[MAX];
            arr[MAX] = temp;
            cheapish(arr, n, MAX);
        }
    }

    public void display(int[] arr)
    {
        for (int j : arr) {
            System.out.print(j + " ");
        }
    }
}
