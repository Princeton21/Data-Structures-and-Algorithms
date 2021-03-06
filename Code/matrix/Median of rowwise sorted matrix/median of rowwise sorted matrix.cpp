#include <bits/stdc++.h>
using namespace std;

const int maximum=100;
int matrixMedian(int mat[][maximum],int r,int c)
{
    int min=mat[0][0],max=mat[0][c-1];
    for(int i=1;i<r;i++)
    {
        if(mat[i][0]<min)
         min=mat[i][0];
        if(mat[i][c-1]>max)
         max=mat[i][c-1];
    }
    int medianpos=(r*c+1)/2;
    while(min<max)
    {
        int mid=(min+max)/2;
        int midpos=0;
        for(int i=0;i<r;i++)
         midpos=midpos + upper_bound(mat[i], mat[i]+c, mid) - mat[i];
        if(midpos<medianpos)
         min=mid+1;
        else
         max=mid;
    }
    return min;
}
int main()
{
	int r = 3, c = 5;
	int m[][maximum]= { {2,4,6,8,10}, {1,3,5,7,9}, {100,200,400,500,800} };
	cout << "Median is " << matrixMedian(m, r, c) << endl;
	return 0;
}