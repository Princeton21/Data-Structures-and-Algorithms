#include<bits/stdc++.h>
using namespace std;

 stack<int>s;
    void MinStack() {
        while(!s.empty())s.pop();
    }
    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            s.push(val);
        }else{
            int x = s.top();
            s.push(val);
            s.push(min(x,val));
        }
    }
    
    void pop() {
        if(s.empty())return;
        s.pop();
        s.pop();
    }
    
    int top() {
        if(s.empty())return -1;
        int x = s.top();s.pop();
        int y = s.top();
        s.push(x);
        return y;
    }
    
    int getMin() {
        if(s.empty())return -1;
        return s.top();
    }

int main(){

    MinStack();
    push(1);
    push(3);
    push(100);
    push(4);
    push(-10000);

    cout<<getMin()<<endl;
    cout<<top()<<endl;
    pop();
    cout<<getMin()<<endl;

}


