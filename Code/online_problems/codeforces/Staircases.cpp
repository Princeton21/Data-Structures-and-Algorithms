/* Problem link 
https://codeforces.com/contest/1598/problem/E
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1005;
int n,m,q,t[N][N];ll ans,cnt,p[N][N][2];
void xxx(int x,int y){
    if(x>n||y>m)return;
    ans-=p[x][y][0]+p[x][y][1];
	if(t[x][y])p[x][y][0]=p[x][y][1]=0;
	else p[x][y][0]=p[x-1][y][1]+1,p[x][y][1]=p[x][y-1][0]+1;
	ans+=p[x][y][0]+p[x][y][1];
}
int main(){
    scanf("%d%d%d",&n,&m,&q);cnt=n*m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++){
	    p[i][j][0]=p[i-1][j][1]+1;
        p[i][j][1]=p[i][j-1][0]+1;
        ans+=p[i][j][0]+p[i][j][1];
    }
	for(int i=1;i<=q;i++){
	    int x,y;scanf("%d%d",&x,&y);
		t[x][y]?cnt++:cnt--;t[x][y]^=1;xxx(x,y);
		for(x++,y++;x<=n+1&&y<=m+1;x++,y++)
		xxx(x-1,y),xxx(x,y-1),xxx(x,y);
		printf("%lld\n",ans-cnt);
	}
}