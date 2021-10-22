// Quicksort algorithm by taking last element as pivot

#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partitionIndex(int *arr, int l, int r)
{
    int i = l - 1;
    int pivot = arr[r];

    for(int j = l; j < r; ++j)
    {
        if(arr[j] <= pivot)
        {
            ++i;
            swap(&arr[i], &arr[j]);
        }
        swap(&arr[i+1], &arr[r]);
    }
    return (i+1);
}

void quicksort(int *arr, int l, int r)
{
    int index;
    if(l < r)
    {
        index = partitionIndex(arr, l ,r);
        quicksort(arr, l, index-1);
        quicksort(arr, index+1, r);
    }
}

int main()
{
    //Sample input
    int arr[] = {106, 503, 444, 22, 90, 34, 108, 34, 73, 88, 66, 444, 10, 90};
    int n = sizeof(arr) / sizeof(int);

    quicksort(arr, 0, n-1);
    
    for(int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}