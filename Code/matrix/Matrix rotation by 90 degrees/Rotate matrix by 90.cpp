#include <bits/stdc++.h>
using namespace std;
const int n=5;
void rotate90(int mat[n][n])
{
    for(int i=0;i<n;i++)
      for(int j=i+1;j<n;j++)
        swap(mat[i][j],mat[j][i]); //finding transpose of matrix

    for(int i=0;i<n;i++)
    {
        int low=0,high=n-1;
        while(low<high)
        {
            swap(mat[low][i],mat[high][i]);//reversing individual columns
            low++;
            high--;
        }
    }
}
int main()
{
    int i,j;
    int mat[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>mat[i][j];//inputting the matrix
        }
    }
    rotate90(mat);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<mat[i][j]<<" ";//displaying the matrix
        }
        cout<<endl;
    }
}