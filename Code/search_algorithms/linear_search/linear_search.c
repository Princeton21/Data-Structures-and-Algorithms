//Doing linear seach in array with O(n) time complexity
#include<stdio.h>


int search_no(int arr[],int n,int x){

    for (int i = 0; i < n; i++)
    {
        if (arr[i]==x)
        {
            return i;
        }
        
    }
    return -1;
    



}

int main(){

    int arr[]={1,4,3,5,19,12};
    int x=5;
    int n=sizeof(arr)/sizeof(arr[0]);

    int result =search_no(arr,n,x);
    if (result==-1)
    {
     printf("No such element present");
    }
    else{
        printf("Element present at index %d",result);
    }


    return 0;
}