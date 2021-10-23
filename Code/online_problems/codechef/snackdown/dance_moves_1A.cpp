//solution in cpp for the first problem dance moves of round 1A of codechef snackdown comtest

#include <bits/stdc++.h>
const int mod=1e9 + 7;
using namespace std;
#define ll long long
#define tc int t;cin>>t;
#define endl "\n"
#define fast_io  ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define all(v) v.begin(),v.end()

void solve(){
    int x,y;
    cin>>x>>y;
    if(x<=y){
        cout<<(y-x+1)/2 + (y-x)%2<<endl;
    }else{
        cout<<(x-y)<<endl;
    }
    
}


int main() {
fast_io;
tc;
while(t--){
    solve();
}

return 0;
}
