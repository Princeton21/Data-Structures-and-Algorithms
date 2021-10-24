#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        unsigned long long ans=0;
        string s;
        cin>>s;
        unordered_map<int,int>map_i,mapi;
        for(int i=0;i<n;i++)
        {
            int temp=s[i]-'0';
            map_i[temp-i]++;
		    mapi[temp+i]++;
        }
        for(auto ele:map_i)
        {
            ans=ans+ele.second*(ele.second-1)/2;
        }
        for(auto ele:mapi)
        {
            ans=ans+ele.second*(ele.second-1)/2;
        }
        cout<<ans<<endl;
    }
    return 0;
}