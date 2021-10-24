#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int max(int a, int b)
{
    return a > b ? a : b;
}


int knapsack(int value[], int weights[], int capacity, int n)
{
    int t[n + 1][capacity + 1];
    int i, j;

    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= capacity; j++)
        {
            if(i == 0 || j == 0)
            {
                t[i][j] = 0;
            }

            else if(weights[i - 1] <= j)
            {
                t[i][j] = max(value[i - 1] + t[i - 1][j - weights[i - 1]], t[i - 1][j]);
            }

            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][capacity];
}


int main()
{
    int n, i, capacity, size;
    double time_spent = 0.0;

    printf("\nEnter the size of the array: ");
    scanf("%d", &n);
    printf("\nEnter the capacity of the sack: ");
    scanf("%d", &capacity);

    int value[n];
    int weights[n];

    printf("\nEnter the values:");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &value[i]);
    }

    printf("\nEnter the weights:");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &weights[i]);
    }

    size = sizeof(value)/sizeof(value[0]);

    clock_t start = clock();
    printf("The value for Knapsach problem is %d", knapsack(value, weights, capacity, size));
    clock_t end = clock();

    time_spent += (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nThe execution time of Knapsack is %f", time_spent );

    return 0;
}
