#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n, i, j;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
       for(i=1; i<=n; i++) {
        for(j=1; j<=i; j++) {
            printf("%d ", n-j+1);
        }
        for(j=1; j<=n-i; j++) {
            printf("%d ", n-i+1);
            printf("%d ", n-i+1);
        }
        for(j=2; j<=i; j++) {
            printf("%d ", n-i+j);
        }
        printf("\n");
    }
    
    for(i=2; i<=n; i++) {
        for(j=1; j<=n-i; j++) {
            printf("%d ", n-j+1);
        }
        for(j=2; j<=i; j++) {
            printf("%d ", i);
            printf("%d ", i);
        }
        for(j=0; j<=n-i; j++) {
            printf("%d ", j+i);
        }
        printf("\n");
    }
    return 0;
}
