#include<iostream>
using namespace std;

int drawTreeLevels(int n, int space)
{
int i,j,s;
for(i=1; i<=n; i++)
{
s=n-i+space;
while(s!=0)
{
cout<<" "; 
s--;
}
for(j=1; j<=i*2-1; j++)
{
cout<<"* ";
}
cout<<"\n";
}
}
int main()
{
int i,n,s,l=2;
cout<<"Enter the number of tree levels ";
cin>>n;
cout<<"The Tree";
while(l<=n+1)
{
 s=n-l+1;
 drawTreeLevels(l,s);
 l++;
}
for(i=1;i<n;i++)
{
 s=n*2-1;
 while(s!=0)
 {
 cout<<" "; 
 s--;
 }
 cout<<"| |"<<endl;
}
}
