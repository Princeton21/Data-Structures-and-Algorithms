#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,x;
        cin>>n;
        cin>>x;
        set<long long>set1;
        long long temp;
        for(long long i=0;i<n;i++)
        {
            cin>>temp;
            set1.insert(temp);
        }
        long long temp2=n-set1.size();
        if(x>temp2)
        {
            cout<<set1.size()-(x-temp2)<<endl;
        }
        else
        {
            cout<<set1.size()<<endl;
        }
    }
    
}