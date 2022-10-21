#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main()
{
    int N;
    scanf("%d", &N);
    int arr[N];
    for(int i=0;i<N;i++){
        scanf("%d", &arr[i]);
    }
    int X;
    scanf("%d", &X);
    int result = binarySearch(arr, 0, N - 1, X);
    (result == -1)
        ? printf("Element not found")
        : printf("Element found at %d", result);
    return 0;
}
