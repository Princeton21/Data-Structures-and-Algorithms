 //Saddle Point

#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define ll long long

int main() {
ios::sync_with_stdio(0);
cin.tie(NULL);cout.tie(NULL);
int m,n;
int x=0;
cin>>m>>n;
int arr[m][n];
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        cin>>arr[i][j];
    }
}
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        x=arr[i][j];
        int min=INT_MAX;
        int max=INT_MIN;
        for(int k=0;k<m;k++){
            if(arr[k][j]>max){
                max=arr[k][j];
            }
        }
        for(int p=0;p<n;p++){
            if(arr[i][p]<min){
                min=arr[i][p];
            }
        }
        if(min==x && max==x){
            cout<<x<<" at position ("<<i<<','<<j<<") is a saddle point "<<endl;
        }
        // }else{
        //     cout<<"NO"<<endl;
        // }
    }
}






return 0;
}
