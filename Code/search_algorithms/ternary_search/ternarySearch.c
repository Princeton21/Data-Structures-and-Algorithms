#include<stdio.h>
#include<stdlib.h>

// ternary search function
int ternarySearch(int l, int r, int key, int * arr){
    if (r >= l){
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        if (arr[mid1] == key){
            return mid1;
        }
        if (arr[mid2] == key){
            return mid2;
        }
        if (key < arr[mid1]){
            return ternarySearch(l, mid1 - 1, key, arr);
        }
        else if (key > arr[mid2]){
            return ternarySearch(mid2 + 1, r, key, arr);
        }
        else{
            return ternarySearch(mid1 + 1, mid2 - 1, key, arr);
        }
    }
    return -1;
}

int main(){
    int n;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int * ptr=(int *)malloc(n*sizeof(int));
    printf("Enter the array: ");
    scanf("%d",ptr+0);
    //taking input along with sorting
    for(int i=1;i<n;i++){
        scanf("%d", ptr + i);
        for(int k=i;k>0;k--){
            if(ptr[k]<ptr[k-1]){
                int t=ptr[k-1];
                ptr[k-1]=ptr[k];
                ptr[k]=t;
            }
            else{
                break;
            }
        }
    }
    int l, r, key;
    l = 0;
    r = n-1;
    printf("Enter the number you want to search: ");
    scanf("%d",&key);
    int tsearch=ternarySearch(l,r,key,ptr);
    if(tsearch==-1){
        printf("Not found\n");
    }
    else{
        printf("Found\n");
    }
    return 0;
}