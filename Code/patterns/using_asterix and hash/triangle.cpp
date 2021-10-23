// C++ code to demonstrate star pattern
#include <iostream>
using namespace std;

// Function to demonstrate printing pattern
void pypart(int n)
{
	int i = 0, j = 0, k = 0;
	while (i < n) {	
		// for spacing
		while (k <= n - i - 2) {
			cout << " ";
			k++;
		}
		k = 0;	
		// For Pattern printing
		while (j < 2 * i - 1) {
			cout << "*";
			j++;
		}
		j = 0;
		i++;
		cout << endl;
	}
}

/*
Sample output
   *
  ***
 *****
*******
*/

// Driver Code
int main()
{
	int n ;
    cout<<"Enter no. of rows:";
    cin>>n;
	// Function Call
	pypart(n);
	return 0;
}
