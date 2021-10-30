#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 40//  w w w .  j ava  2  s.co  m

int main()
{
    int bubble[SIZE];
    int inner,outer,temp,x;

    srand((unsigned)time(NULL));
/* Display original array */
    puts("Original Array:");
    for(x=0;x<SIZE;x++)
    {
        bubble[x] = rand();
        bubble[x] = (bubble[x] % 100)+1;
        printf("%d\t",bubble[x]);
    }
    putchar('\n');

/* Bubble sort */
    for(outer=0;outer<SIZE-1;outer++)
    {
        for(inner=outer+1;inner<SIZE;inner++)
        {
            if(bubble[outer] > bubble[inner])
            {
                temp=bubble[outer];
                bubble[outer] = bubble[inner];
                bubble[inner] = temp;
            }
        }
    }

/* Display sorted array */
    puts("Sorted Array:");
    for(x=0;x<SIZE;x++)
        printf("%d\t",bubble[x]);
    putchar('\n');

    return(0);
}
