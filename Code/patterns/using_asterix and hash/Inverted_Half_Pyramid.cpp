#include<iostream>
using namespace std;
int main()
{
    int a;
    cout<<"Enter no. of rows: ";
    cin>>a; 
    int b=a;
    for(int i=0;i<a;i++)
    {
        for(int j=b;j>0;j--)
        {   cout<<"*";  }
        b--;
        cout<<"\n";
    }
    return 0;
}