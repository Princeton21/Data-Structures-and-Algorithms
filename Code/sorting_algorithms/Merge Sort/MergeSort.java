/**
 * Merge sort
 */
public class MergeSort {
    public void sort(int[] arr) {
        if (arr == null || arr.length == 0) {
            return;//check corner case
        }
        int[] tmp = new int[arr.length];
        sort(0, arr.length - 1, arr, tmp);

    }

    private void sort(int start, int end, int[] arr, int[] tmp) {
        if (start >= end) {
            return;
        }
        int mid = start + (end - start) / 2; //get middle of array
        sort(start, mid, arr, tmp);
        sort(mid + 1, end, arr, tmp);
        int tmpStart = start;
        int leftStart = start;
        int rightStart = mid + 1;
        //do merging array
        while (leftStart <= mid && rightStart <= end) {
            if (arr[leftStart] <= arr[rightStart]) {
                tmp[tmpStart++] = arr[leftStart++];
            } else {
                tmp[tmpStart++] = arr[rightStart++];
            }
        }
        //continue for remaining left side
        while (leftStart <= mid) {
            tmp[tmpStart++] = arr[leftStart++];
        }
        //continue for remaining right side
        while (rightStart <= end) {
            tmp[tmpStart++] = arr[rightStart++];
        }
        for (int i = start; i <= end; i++) {
            arr[i] = tmp[i];
        }


    }
    public static void printArr(int[]arr){
        for(int i : arr){
            System.out.print("\t"+i);
        }
        System.out.println();
    }
    public static void main(String[]args){
        int[] arr = { 3, 4,1, 2, 10, 11, 0, 9};
        System.out.println("before sorting:");
        printArr(arr);
        MergeSort mergeSort = new MergeSort();
        mergeSort.sort(arr);
        System.out.println("after sorting:");
        printArr(arr);

    }
}
