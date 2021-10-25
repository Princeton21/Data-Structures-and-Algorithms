#include<iostream>
using namespace std;
int main()
{
    int arr[10], i;
    cout<<"Enter 10 Array Elements: ";
    for(i=0; i<10; i++)
        cin>>arr[i]; // taking input array
    cout<<"\nThe Original Array is:\n";
    for(i=0; i<10; i++)
        cout<<arr[i]<<" ";//printing original array
    cout<<"\n\nThe Reverse of Given Array is:\n";
    for(i=(10-1); i>=0; i--)//iterating from the last element to the first 
        cout<<arr[i]<<" "; // printing array in reverse order
    cout<<endl;
    return 0;
}