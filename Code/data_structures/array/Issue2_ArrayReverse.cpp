#include<bits/stdc++.h>
using namespace std;
int main(){
    //here we first make a array
    int a[100],n;
    cout<<"\n\t ENTER THE SIZE OF ARRAY";
    cin>>n;
    cout<<"\n\t KINDLY ENTER THE ELEMENTS OF ARRAY: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"\n\t--------------------------------------"<<endl;
    cout<<"\n\t ARRAY BEFORE REVERSING THE ELEMENTS: "<<endl;
    cout<<"n\t --------------------------------------"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Element"<<i+1<<":"<<a[i]<<endl;
    }
    cout<<"\n\t--------------------------------"<<endl;
    cout<<"\n\t ARRAY AFTER REVERSE OPERATION: "<<endl;
    cout<<"\n\t--------------------------------"<<endl;
    for(int i=n-1;i<0;i--){
        int c = 1; //here i take this variable only for printing purpose
        cout<<"Element"<<c<<":"<<a[i];
        c++;
    }
    return 0;
}

