#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isRedudent(string exp){
    stack<char> symbol;
   
    for( char ch : exp){
        if(ch!=')'){
            symbol.push(ch);
        }
        else{
             bool isOperator=false;
             while(!symbol.empty() && symbol.top()!='('){
                 char currentChar=symbol.top();
                 if(currentChar=='+' || currentChar=='-' || currentChar=='*' || currentChar=='/'){
                     isOperator=true;
                 }
                 symbol.pop();
             }
            symbol.pop();
            if(isOperator==false){
                return true;
             }
        }
    }
 return false;
}

int main(){
    string exp;
    cin>>exp;
    if(isRedudent(exp)){
        cout<<"Yes Expression is redudent"<<endl;
    }else{
        cout<<"No Expression is not redudent"<<endl;
    }
    return 0;
}
