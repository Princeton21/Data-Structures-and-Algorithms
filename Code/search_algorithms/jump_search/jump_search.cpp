/* Jump Search is a searching algorithm for sorted arrays.
* this algorith checks elements by jumping ahead by fixed steps 
* or skipping some elements in place of searching all elements.
* when a element on specific index found to be less than required element
* then it performs Linear search upto that index
*/

// Pros : Better than Linear search 
// Cons : Not better than Binary search.

// Time complexity : O(√n) 

// Algorithm :

#include <bits/stdc++.h>

using namespace std;

int jumpSearch(int array[], int x, int n)
{
	int step = sqrt(n);
	int prev = 0;

	while (array[min(step, n)-1] < x)
	{
		prev = step;
		step += sqrt(n);
		if (prev >= n)
			return -1;
	}

	while (array[prev] < x)
	{
		prev++;
		if (prev == min(step, n))
			return -1;
	}
	if (array[prev] == x)
		return prev;

	return -1;
}

int main()
{
	int array[] = { 1,2,4,8,10,15,20,21,34,39,45,45,50,55,65,70 };
	int x = 55; // number to be searched in array
	int n = sizeof(array); // size of array

	int index = jumpSearch(array, x, n);

	cout << "Number " << x << " is at index " << index <<endl;
	return 0;
}