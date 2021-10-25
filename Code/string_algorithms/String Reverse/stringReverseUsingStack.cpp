#include<iostream>
#include<stack>
#include<string>

using namespace std;

string reverse(string str){
    stack<char> stk;
    string reverse;
    for(int i=0;i<str.length();i++){
        stk.push(str[i]);
    }
    while(!stk.empty()){
        reverse+=stk.top();
        stk.pop();
    }
    return reverse;
}

int main(){
    string str,rev;
    cin>>str;
    rev=reverse(str);
    cout<<rev<<endl;
    return 0;
}
