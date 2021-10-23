#include<iostream>
using namespace std;
int main()
{
    //WAP to print half pyramid
    int a;
    cout<<"Enter the no. of rows: ";
    cin>>a;
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<=i;j++)
        { cout<<"*"; }
        cout<<"\n";
    }
    return 0;
}