#include<iostream>
#include<stack>
#include<string>

using namespace std;


bool isBalanced(string exp){

    stack<char> sym;
    for(auto ch: exp){

        switch(ch){
            case '(':
            case '[':
            case '{': sym.push(ch);
                break;

            case ')':
                if(!sym.empty() and sym.top()=='(')
                    sym.pop();
                else
                   return false;
                break;
            case ']':
                if(!sym.empty() and sym.top()=='[')
                    sym.pop();
                else
                   return false;
                break;
            case '}':
                if(!sym.empty() and sym.top()=='{')
                    sym.pop();
                else
                   return false;
                break;
            default:
             continue;
        }
        
    }
    if(sym.empty()==true){
            return true;
        }else{
            return false;
        }
}

int main(){
    string exp;
    cin>>exp;
    if(isBalanced(exp)==true){
        cout<<"Balanced..!"<<endl;
    }
    else{
        cout<<"Not Balanced...!"<<endl;
    }

    return 0;
}
