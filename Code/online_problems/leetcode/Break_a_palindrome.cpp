
#include<bits/stdc++.h>
#define inf INT_MAX
using namespace std;

string breakPalindrome(string p) {
        if(p.length()==1)return "";
        
            int n = p.length();
            for(int i=0;i<n/2;i++){
                if(p[i]=='a')continue;
                else {
                    p[i] = 'a';
                    return p;
                }
            }
        
        p[n-1] = 'b';
        return p;
    }

int main(){

  string s = "abccba";
  cout<<breakPalindrome(s)<<endl;

  return 0;
}
