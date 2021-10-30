#include<bits/stdc++.h>
#include <math.h>
#define int long long int
#define setbits(x)  __builtin_popcountll(x)
#define zrobits(x)  __builtin_ctzll(x)   //no of zero bits befor the first set bits
#define inf         1e9
#define ps(x,y)     fixed<<setprecision(y)<<x
#define w(x)        int x; cin>>x; while(x--)
#define rep(i,a,b)  for(int i = a; i < b; i++)
#define Rep(i,a,b)  for(int i = a; i <= b; i++)
#define ff          first
#define ss          second
#define pb          push_back
#define INF         998244353
#define mod         1e9 + 7
#define pii         pair<int,int>
#define mxhi        priority_queue<int>
#define mnhi        priority_queue<int,vi,greater<int>>
using namespace std;
 
struct node {int x1, y1, x2, y2, x3, y3;} p[5];
int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
 
struct man{
	int h,w,id;
};
 
int power(int x, int y, int m){
    if (y == 0)
        return 1;
    int p = power(x, y / 2, m) % m;
    p = (p * p) % m;
 
    return (y % 2 == 0) ? p : (x * p) % m;
}
 
const int MAX = 10000000 + 2;
bool prime[MAX];
 
void sieve(){
	prime[0] = prime[1] = 1;
	for(int p=2;p*p<=10000000;p++){
		if(!prime[p]){
			for(int j=p*p;j<=10000000;j+=p){
				prime[j] = 1;
			}
		}
	}
}
 
 
void solve(){
 
	int n;cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
 
	int maxie = *max_element(a,a+n);
	int cnt = count(a,a+n,maxie);
	int nd = count(a,a+n,maxie-1);
 
	int ans = 1;
	int s = 1;
	for(int i=1;i<=n;i++){
		ans = (ans*i)%INF;
		if(i!=nd+1)s = (s*i)%INF;
	}
 
	if(cnt==1)ans = (ans - s + INF)%INF;
	cout<<ans<<endl;
 
 
}
 
 
int32_t main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	
    int t;
    cin>>t;
    // t = 1;
    for(int test=1;test<=t;test++){
        // cout<<"Case #"<<test<<": ";
    	solve();
    }
 
	return 0;
} 
