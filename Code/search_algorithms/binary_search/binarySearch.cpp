#include <iostream>
#include <stdlib.h>

using namespace std;

//Binary Search function
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Else the element can only be present in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}

int main(){
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    int *ptr = (int *)malloc(n * sizeof(int));
    cout<<"Enter the array: ";
    scanf("%d", ptr + 0);
    //taking input along with sorting
    for (int i = 1; i < n; i++)
    {
        scanf("%d", ptr + i);
        for (int k = i; k > 0; k--)
        {
            if (ptr[k] < ptr[k - 1])
            {
                int t = ptr[k - 1];
                ptr[k - 1] = ptr[k];
                ptr[k] = t;
            }
            else
            {
                break;
            }
        }
    }
    int x;
    cout<<"Enter the number that you want to find: ";
    cin>>x;

    int result = binarySearch(ptr, 0, n - 1, x);
    if(result==-1){
        cout<<"Number not found";
    }
    else{
        cout << "Number found";
    }
    
    
    return 0;
}
