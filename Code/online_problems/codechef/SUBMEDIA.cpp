#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long int n;
        long int k;
        cin>>n>>k;
        int arr[n];
        int arr2[n];
        for(long int i=0;i<n;i++)
        {
            cin>>arr[i];
            arr2[i]=arr[i];
        }
        sort(arr,arr+n);
        int index2=n-1;
        int index1=n-k;
        int temp=0;
        if(k%2==0)
        {
            int temp1=(index2+index1-1)/2;
            temp=arr[temp1];
        }
        else
        {
            int temp1=(index2+index1)/2;
            temp=arr[temp1];
        }
        cout<<temp<<endl;
        unordered_set<int> s;
        for(long int i=index1;i<=index2;i++)
        {
            s.insert(arr[i]);
        }
        for(long int i=0;i<n;i++)
        {
            if(s.find(arr2[i])!=s.end())
            {
                cout<<arr2[i]<<" ";
            }
        }
    }
    return 0;
}