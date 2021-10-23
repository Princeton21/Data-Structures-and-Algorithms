// C++ program for printing a diamond pattern
#include <bits/stdc++.h>
#define ll long long int 
using namespace std;

int main()
{
    for(int i=-5;i<=5;i++)
    {
        for(int j=-5;j<=5;j++)
        {
            if((abs(i)+abs(j))<=5)
            {
                cout<<"*";
            }
            else
            cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
} 

/* OUTPUT

     *     
    ***    
   *****   
  *******  
 ********* 
***********
 ********* 
  *******  
   *****   
    ***    
     *     

*/
