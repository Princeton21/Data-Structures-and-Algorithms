#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,r;
        cin>>n;
        cin>>r;
        long long arr1[n],arr2[n];

        for(long long i=0;i<n;i++)
        {
            cin>>arr1[i];
        }
        for(long long i=0;i<n;i++)
        {
            cin>>arr2[i];
        }
        long long tension=arr2[0];

        long long temp=0;
        long long res=arr2[0];
        if(n==1)
        {
            cout<<arr2[0]<<endl;
        }

        else
        {

        for(long long i=1;i<n;i++)
        {
            temp=arr1[i]-arr1[i-1];
            tension=tension-(temp*r);

            if(tension<0)
            {

                tension=0;
            }
            //cout<<tension+arr2[i]-rest<<endl;
            //tension = tension +arr2[i-1]-rest;
            tension = arr2[i] + tension;
            res=max(res,tension);
            
        }
                cout<<res<<endl;
        }

    }
}