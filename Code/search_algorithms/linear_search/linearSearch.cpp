#include<iostream>
#include<stdlib.h>

using namespace std;

// Binary Search Function
int binarySch(int *arr, int n, int x){
    for (int i = 0; i < n; i++){
        if(arr[i]==x){
            return i;
        }
    }
    return -1;   
}


int main(){
    int n;  // size of array
    cout<<"Enter the size of array : ";
    cin>>n;
    //using dynamic memeory allocation
    int * ptr=(int *)malloc(n* sizeof(int));
    cout << "Enter the array : ";
    for(int i=0;i<n;i++){
        cin>>ptr[i];
    }

    int x;
    cout << "Enter the number that you want to search : ";
    cin>>x;

    //Calling search function
    int search=binarySch(ptr,n,x);
    if(search==-1){
        cout<<"Your number is not found in array"<<endl;
    }
    else{
        cout << "Your number is found at index :"<<search<<endl;
    }



    return 0;
}
