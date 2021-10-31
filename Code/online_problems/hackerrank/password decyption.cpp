#include <bits/stdc++.h>

using namespace std;



/*
 * Complete the 'decryptPassword' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
void decryptPassword(string s) {
     string p;
    int i=0;
    int count=-1;
    while(i<s.length())
    {
        if(s[i]>='1'&&s[i]<='9')
        count++;
        else
        break;
        i++;
       
    }
    i=count+1;
    while(i<s.length())
    {
       
       
         if((s[i]>='A'&&s[i]<='Z')&&(s[i+1]>='a'&&s[i+1]<='z')&&(s[i+2]=='*')&&((i+2)<=(s.length()-1)))
        {
        p.push_back(s[i+1]);
        p.push_back(s[i]);
       
       
        i=i+3;
      
        }
        else if(s[i]=='0')
        {
            p.push_back(s[count]);
            count--;
           
            i++;
            
            
        }
        else
        {
            p.push_back(s[i]);
           
        i++;
        
        }
    }
    cout<<p<<"\n";
           
}

int main()

{
    

    string s;
    cin>>s;

     decryptPassword(s);

   

   

    return 0;
}
