#include <iostream>
using namespace std;
int main() {
    int num1, num2;
    cout<<"Enter the 2 numbers whose LCD is to be determined: ";
    cin>>num1>>num2;
    int LCD,GCD,MAX;
    //HERE WE WILL BE USING THE MATHEMATICAL RELATION TO DETERMINE THE LCD OF 2 NUMBERS
    //Product of 2 numbers= LCD(num1,num2)*GCD(num1,num2)
    //LCD=(num1*num2)/GCD
    if(num1>num2)
    MAX=num1;
    else 
    MAX=num2;
    for (int i = 1; i <=MAX ; i++) {
        if ((num1 % i == 0) && (num2 % i == 0)){ //This condition ensures that i divides both the numbers
            GCD = i;
        }
    }
    LCD = (num1 * num2) / GCD;
    cout<<"The Least Common Divisor of the 2 inputted numbers is: "<<LCD;
    return 0;
}
