#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define deb(x) cout<<#x<<"="<<x<<endl
#define deb2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define tr(it,a) for(auto it=a.begin(); it!=a.end();it++)
#define nl '\n'
#define PI 3.1415926535897932384626
#define mod 1000000007

typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

const int N=1e6+10;

void solve(){
    int i,j;
    int n;
    cin>>n;
    ll a[n],ans=1e12,l,r,diff,temp,pref[n+1]={0},rem,curr,done;
    fo(i,n){
        cin>>a[i];
    }
    sort(a,a+n);
    fo2(i,1,n){
        pref[i]=pref[i-1]+a[i-1];
    }
    if(n==2){
        cout<<"0\n";
        return;
    }
    if(n==3){
        cout<<min(a[1]-a[0],a[2]-a[1])<<nl;
        return;
    }
    
    i=1;
    j=n-2;
    while(i<j){
        l=a[i]-a[0];
        r=a[n-1]-a[j];
        diff=abs(l-r);
        
        ans=min(ans,diff);

        if(l<r){
            i++;
        }
        else{
            j--;
        }
    }
    curr=0;
    fo2(i,1,n-1){
        rem=n-1-i;
        done=i-1;
        r=pref[n-1]-pref[i]-rem*a[i-1];
        l=done*a[i-1]-curr;
        temp=l+r;
        ans=min(ans,temp);
        curr+=a[i-1];
    }

    curr=0;
    fo2(i,2,n){
        rem=n-i;
        done=i-2;
        r=pref[n]-pref[i]-rem*a[i-1];
        l=done*a[i-1]-curr;
        // deb2(l,r);
        temp=l+r;
        ans=min(ans,temp);
        curr+=a[i-1];
    }

    cout<<ans<<nl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    
}

