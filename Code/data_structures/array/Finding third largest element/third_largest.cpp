// C++ program to find third Largest
// element in an array of distinct elements
#include <bits/stdc++.h>
#include<stdio.h>
#include <stdlib.h>
using namespace std;

void thirdLargest(int arr[], int arr_size)
{
	/* There should be atleast three elements */
	if (arr_size < 3)
	{
		cout<<"-1";
		return;
	}

	// Find first largest element
	int first = arr[0];
	for (int i = 1; i < arr_size ; i++)
		if (arr[i] > first)
			first = arr[i];

	// Find second largest element
	int second = INT_MIN;
	for (int i = 0; i < arr_size ; i++)
		if (arr[i] > second && arr[i] < first)
			second = arr[i];

	// Find third largest element
	int third = INT_MIN;
	for (int i = 0; i < arr_size ; i++)
		if (arr[i] > third && arr[i] < second)
			third = arr[i];

	printf("The third Largest element is %d\n", third);
}

/* Driver program to test above function */
int main()
{
	
	int n,i;
    cout<<"\nEnter no of elements:";
    cin>>n;

    int *arr;
    arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("\nMemory not allocated.\n");
        exit(0);
    }
    else {
        cout<<"\nEnter "<<n<<" Array elements\n";
    // Get the elements of the array
    for (i = 0; i < n; ++i) {
        cin>>arr[i];    }
    }
	thirdLargest(arr, n);
	return 0;
}
