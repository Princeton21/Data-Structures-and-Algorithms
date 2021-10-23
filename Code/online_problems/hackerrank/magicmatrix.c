#include <stdio.h>
int main(){
    int arr1[3][3]={{8,3,4},{1,5,9},{6,7,2}};
    int arr2[3][3]={{8,1,6},{3,5,7},{4,9,2}};
    int arr3[3][3]={{4,3,8},{9,5,1},{2,7,6}};
    int arr4[3][3]={{6,1,8},{7,5,3},{2,9,4}};
    int arr5[3][3]={{2,7,6},{9,5,1},{4,3,8}};
    int arr6[3][3]={{2,9,4},{7,5,3},{6,1,8}};
    int arr7[3][3]={{4,9,2},{3,5,7},{8,1,6}};
    int arr8[3][3]={{6,7,2},{1,5,9},{8,3,4}};
    int arr[3][3];
    int arrc[8]={0,0,0,0,0,0,0,0};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
    scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
         if(arr[i][j]>=arr1[i][j]){
             arrc[0]=arrc[0]+(arr[i][j]-arr1[i][j]);
         }else{
             arrc[0]=arrc[0]+(arr1[i][j]-arr[i][j]);
         }
        }
    }
     for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
         if(arr[i][j]>=arr2[i][j]){
             arrc[1]=arrc[1]+(arr[i][j]-arr2[i][j]);
         }else{
             arrc[1]=arrc[1]+(arr2[i][j]-arr[i][j]);
         }
        }
    }
     for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
         if(arr[i][j]>arr3[i][j]){
             arrc[2]=arrc[2]+(arr[i][j]-arr3[i][j]);
         }else{
             arrc[2]=arrc[2]+(arr3[i][j]-arr[i][j]);
         }
        }
    }
     for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
         if(arr[i][j]>arr4[i][j]){
             arrc[3]=arrc[3]+(arr[i][j]-arr4[i][j]);
         }else{
             arrc[3]=arrc[3]+(arr4[i][j]-arr[i][j]);
         }
        }
    }
     for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
         if(arr[i][j]>arr5[i][j]){
             arrc[4]=arrc[4]+(arr[i][j]-arr5[i][j]);
         }else{
             arrc[4]=arrc[4]+(arr5[i][j]-arr[i][j]);
         }
        }
    }
        for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
         if(arr[i][j]>arr6[i][j]){
             arrc[5]=arrc[5]+(arr[i][j]-arr6[i][j]);
         }else{
             arrc[5]=arrc[5]+(arr6[i][j]-arr[i][j]);
         }
        }
        }
       
        for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
         if(arr[i][j]>arr7[i][j]){
             arrc[6]=arrc[6]+(arr[i][j]-arr7[i][j]);
         }else{
             arrc[6]=arrc[6]+(arr7[i][j]-arr[i][j]);
         }
        }
     }
     for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
         if(arr[i][j]>arr8[i][j]){
             arrc[7]=arrc[7]+(arr[i][j]-arr8[i][j]);
         }else{
             arrc[7]=arrc[7]+(arr8[i][j]-arr[i][j]);
         }
        }
     }
     int min =arrc[0];
     for(int i=0;i<8;i++){
         if(arrc[i]<min){
             min=arrc[i];
         }
         
     }
     printf("%d",min);
        
    return 0;
    
}
