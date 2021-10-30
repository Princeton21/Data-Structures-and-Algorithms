
#include<bits/stdc++.h>
using namespace std;
class MyQueue {
public:
    stack<int> s1, s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        
        while(!s1.empty()){
            int temp = s1.top();
            s2.push(temp);
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            int temp = s2.top();
            s1.push(temp);
            s2.pop();
        }
    }
    
    int pop() {
        int temp = s1.top();
        s1.pop();
        return temp;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

int main(){

    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
 
    cout << q.pop() << '\n';
    cout << q.pop() << '\n';
    cout << q.pop() << '\n';
 
 
    return 0;
}
