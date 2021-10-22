#include<stdio.h>
    
    //we use binary search for sorted array for time complexity Log(n)
   int  binary_search(int arr[],int size,int element){
        int low=0;
        int high=size-1;

        while (low<=high)
        {
        int mid=(low+high)/2;
            
            
        if (arr[mid]==element)
        {
            return mid;

        }
        if (arr[mid]<element)
        {
            low=mid+1;
            
        }
        else{
            high=mid-1;
        }
        }
        return -1;
        

    }
    
int main()
{
    //random sorted array on which binary search to be applied
    int arr[]={1,2,44,55,99,198,222};
    
    int size=sizeof(arr)/sizeof(arr[0]);
    int element;
    scanf("%d",&element);

 int result= binary_search(arr,size,element); 
 printf("the index of %d element is %d",element,result);

    
return 0;
}