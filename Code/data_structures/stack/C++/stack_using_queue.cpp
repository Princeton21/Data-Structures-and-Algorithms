
#include<bits/stdc++.h>
using namespace std;

class MyStack {
    queue <int> q1 ;
   
public:
    MyStack() {
        queue <int> q1 ;
      
    }
    
    void push(int x) {        //Pushing item into the rear of the queue or top of previous item
        q1.push(x);
    }
    
    int pop() {
        int front = q1.front();                       
        int rear =  q1.back() ;                      
        swap(q1.front(), q1.back());       
        q1.pop();                          
        swap(q1.front(), q1.back());   
        return rear ;    
        
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        return q1.empty();
    }
};

int main(){

    class MyStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " Popped from stack\n";

    cout<<"Elements present in stack : ";
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
 
    return 0;
}
