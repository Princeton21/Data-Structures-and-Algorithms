#include<iostream>
using namespace std;
void solidRhombus(int n)
{
    int i, j;
    for (i=1; i<=n; i++)
    {
        // Print spaces
        for (j=1; j<=n - i; j++)
            cout << " ";
             
        // Print stars after spaces
        for (j=1; j<=n; j++)
            cout << "* ";
             
        // Move to the next line/row
        cout << "\n";
    }
}
int main()
{
	
	/*int k;
	cout<<"Enter height of rhombus:"<<endl;
	cin>>k;
	solidRhombus(k);*/
	solidRhombus(5);


/* sample output:with height=5	
    * * * * *
   * * * * *
  * * * * *
 * * * * *
* * * * *   */
	
}
