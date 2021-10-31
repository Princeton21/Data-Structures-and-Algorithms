// C++ code for k largest elements in an array
#include <bits/stdc++.h>
using namespace std;

void kLargest(int arr[], int n, int k)
{
	// Sort the given array arr in reverse
	// order.
	sort(arr, arr + n, greater<int>());
	
	// Print the first kth largest elements
	if(k>n)
	{
		cout<<"Not possible to find "<<k<<"th maximum element in the array as k>n";
	}
	else{
			cout <<"\n"<<k<<"th largest element : "<< arr[k-1];
	}
	
}

// driver program
int main()
{
	//int arr[] = { 1, 23, 12, 9, 30, 2, 50 };
	int n,i,k;
    cout<<"\nEnter no of elements:";
    cin>>n;
    
    cout<<"\nEnter K value for finding kth max element:";
    cin>>k;
    
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

	kLargest(arr, n, k);
}


