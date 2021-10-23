// C++ program for printing Transpose of a n*m matrix
#include <bits/stdc++.h>
#define ll long long int 
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"Transpose of the matrix is\n";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[j][i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
} 

/* INPUT
2 3
4 5 2
3 1 7

OUTPUT
Transpose of the matrix is
4 3 
5 1 
2 7 */
