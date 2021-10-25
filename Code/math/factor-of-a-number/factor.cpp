#include <iostream>
 using namespace std;
 int main(){
     int num;
     cout << " please enter the number\n";
     cin >> num;
     cout << "factors of number are (both +ve & -ve): ";
     if(num>0){
     for(int i=1;i<=num;i++){
         if(num%i==0){
             cout  << i <<",";
             cout  << (i*-1) <<",";
         }
     }
       }else{
           for(int i=1;i<=(num*-1);i++){
         if((num*-1)%i==0){
             cout  << i <<",";
             cout  << (i*-1) <<",";
         }
     }
       }
      cout << "\b \b"; 
     return 0;
 }