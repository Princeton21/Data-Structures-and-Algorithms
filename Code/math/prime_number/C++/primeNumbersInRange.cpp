#include<iostream>

using namespace std;

bool isPrime(int n){
    bool flag=true;
    
    if(n==0 || n==1){
       flag=false;
    }
    else{
        for(int i=2;i<n;i++){
            if(n%i==0){
                flag=false;
                break;
            }
        }
    }
   
   if(flag){
       return true;
   }else{
       return false;
   }
}

int main(){
    int start=0,end=0;
    cout<<"Enter range"<<endl;
    cin>>start>>end;
    if(start<end){
        cout<<"Prime Numbers between "<<start<<" & "<<end<<" are :"<<endl;
        for(int i=start;i<=end;i++){
          bool n=isPrime(i);
          if(n){
              cout<<i<<endl;
          }
        }
    }else{
        cout<<"Enter valid range";
    }
    return 0;
}
