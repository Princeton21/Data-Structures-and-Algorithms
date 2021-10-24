#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        long long n,k;
        cin>>n;
        cin>>k;
        long long arr[n];
        long long c1=0,c2=0;
        for(long long i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        long long k1=k,k2=k+1;
        sort(arr,arr+n,greater<long long>());
        for(long long i=0;i<n;i++)
        {
            if(k1>0 || k2>0)
            {
                if(k2==1)
                {
                    c2+=arr[i];
                    k2--;
                }
/*            if((i+1)==(k+2))
            {
                c2+=arr[i];
                cout<<c2<<" ";
                k2--;
            }*/
            else if((i+1)%2==0)
            {
                c2+=arr[i];

                k2--;
            }
            else
            {
                c1+=arr[i];
                k1--;
            }
            }
        }
        if(c1>c2)
        {
            cout<<c1<<endl;
        }
        else
        {
            cout<<c2<<endl;
        }
    }

    return 0;
}