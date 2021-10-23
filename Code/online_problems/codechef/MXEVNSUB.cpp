// Problem: MXEVNSUB Contest: LTIME99C
#include <bits/stdc++.h> 
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n,sum=0,max_sum=0,c=0;
	    cin >> n;
	    if( n%4 == 0 || (n+1)%4 == 0){
	        cout << n << endl;
	    }
	    else{
	        cout << n-1 << endl;
	    }
	}
	return 0;
}