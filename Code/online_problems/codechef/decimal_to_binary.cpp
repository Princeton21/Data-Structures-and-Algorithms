//C++ program to convert decimal to binary

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
   int num, binaryNum = 0;
   int i = 1, rem;

   cout << "Enter any decimal number: ";
   cin >> num;

   //while loop to convert decimal to binary
   while (num != 0)
   {
      rem = num % 2;
      num /= 2;
      binaryNum += rem * i;
      i *= 10;
   }

   cout << "Equivalent Binary Number: " << binaryNum << endl;

   return 0;
}