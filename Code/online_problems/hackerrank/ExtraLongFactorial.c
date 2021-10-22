//Extra Long Factorials on HackerRank( https://www.hackerrank.com/challenges/extra-long-factorials/problem )
//Program in C language for calculation of factorial of a number (even the order of 10^5)
#include <stdio.h>
#include <string.h>

int main()
{
    //Enter the number n for which we are calculating factorial
    int n;
    scanf("%d", &n);

    //using character array to store our number
    char str[2000000];
    memset(str, '\0', sizeof(char) * 2000000);

    str[0] = '1';

    int k;
    int carry;
    for (int i = 1; i <= n; i++)
    {
        carry = 0;
        for (int j = 0;; j++)
        {
            int arr = str[j] - 48; // character to integer conversion.
            k = arr * i + carry;   // the multiplication result with carry.
            arr = k % 10;          /* the value that we will place at that postion  
                                        from the multiplication result.*/
            str[j] = arr + 48;     // integer to characer conversion.
            carry = k / 10;        // other digits will be stored as carry.

            /*case when carry becomes 0 after multiplication with every term that is when 
          we get the final result of that process*/
            if (carry == 0 && str[j + 1] == '\0')
            {
                break;
            }

            /*case when we left with carry after multiplication with all terms and now we
          have to do the same process with carry.*/
            if (carry != 0 && str[j + 1] == '\0')
            {

                for (int r = j;; r++)
                {
                    str[r + 1] = (carry % 10) + 48;
                    carry = carry / 10;

                    if (carry == 0)
                    {
                        str[r + 2] = '\0';

                        break;
                    }
                }
                break;
            }
        }
    }

    int len = strlen(str); //finding string length for printing output.

    //note that we are storing digits in reverse order so we have to print accordingly
    for (int i = 0; i < len; i++)
    {
        int b = len - i - 1;
        printf("%c", str[b]);
    }

    return 0;
}