//C++ program to convert binary to decimal
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
   long long num;
   int decimalNum, i, rem;

   cout << "Enter any binary number: ";
   cin >> num;

   decimalNum = 0;
   i = 0;

   //converting binary to decimal
   while (num != 0)
   {
      rem = num % 10;
      num /= 10;
      decimalNum += rem * pow(2, i);
      ++i;
   }

   cout << "Equivalent Decimal number: " << decimalNum << endl;

   return 0;
}