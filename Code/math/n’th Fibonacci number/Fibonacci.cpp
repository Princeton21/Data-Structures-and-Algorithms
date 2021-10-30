#include<iostream>
using namespace std;
int Fibonacci(int n){
    if(n<=1)//The zeroth term of Fibonacci series is 1 and 1st term is 1
    return n;
    else
    return Fibonacci(n-2)+Fibonacci(n-1);//This statement again calls the function
}
int main(){
  int term;
  //Taking input from the user
  cout<<"Enter the term at which the nth fibonacci number is to be determined: ";
  cin>>term;
  cout<<"The nth Fibonacci number is: "<<Fibonacci(term); //Function called in the main function
}
