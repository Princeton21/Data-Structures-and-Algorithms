#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int i,j;
    ll n,k,copy;
    cin>>n>>k;
    if(k>0 && k%2==0){
        cout<<"NO\n";
        return;
    }

    ll p=1,curr=0,size=0,temp,pos;
    while(p<=k){
        p*=2;
        size++;
    }
    p/=2;
    copy=p;

    vector<ll> v1,v2;
    ll ans[size],end;
    while(p>0){
        if(k>curr){
            v1.push_back(p);
            curr+=p;
        }
        else{
            v2.push_back(p);
            curr-=p;
        }
        p/=2;
    }   
    p=copy;

    
    ans[size-1]=1;

    end=p;
    for(i=v2.size()-1;i>=0;i--){
        temp=v2[i];
        pos=-1;
        while(temp){
            temp/=2;
            pos++;
        }
        ans[pos]=end-v2[i]+1;
        end-=v2[i];
    }

    end=k;
    for(i=v1.size()-1;i>=1;i--){
        temp=v1[i];
        pos=-1;
        while(temp){
            temp/=2;
            pos++;
        }
        ans[pos]=end-v1[i]+1;
        end-=v1[i];
    }

    
    cout<<"YES\n";
    cout<<size<<'\n';
    for(i=0;i<size;i++){   
        cout<<ans[i]<<'\n';
    }

}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    
}

