#include <stdio.h>
int main()
{
    int i, j;
    int n, p, q;
    printf("enter the hight of pyramid: ");
    scanf("%d", &n);
    printf("left half pyramid\n");
    for (i = 1; i <= n; i++)
    {
        for (p = 1; p <=(n - i); p++)
        {
            printf("  ");
            }
            for (j = 1; j <= i; j++)
            {
                printf("* ");
               }
        printf("\n");
    }
    printf("right half pyramid\n");
    for (i = 1; i <= n; i++)
    {
        for (p = 1; p <=i; p++)

        {
            printf("* ");
            }
        printf("\n");
    }
    return 0;
}

