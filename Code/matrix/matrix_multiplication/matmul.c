#include<stdio.h>
int main()
{

    int row1, col1, row2, col2, sum;
    printf("Enter size of first matrix:\n");
    printf("Enter row size: ");
    scanf("%d", &row1);
    printf("Enter column size: ");
    scanf("%d", &col1);
    int mat1[row1][col1];
    printf("\nEnter the element of first matrix:\n");
    for(int i=0; i<row1; i++)
    {
        for(int j=0; j<col1; j++)
            scanf("%d", &mat1[i][j]);
    }
    printf("\nEnter size of second matrix:\n");
    printf("Enter row size: ");
    scanf("%d", &row2);
    printf("Enter column size: ");
    scanf("%d", &col2);
    int mat2[row2][col2];
    printf("\nEnter the element of second matrix:\n");
    for(int i=0; i<row2; i++)
    {
        for(int j=0; j<col2; j++)
            scanf("%d", &mat2[i][j]);
    }
    int resmut[row1][col2];
    if(col1!=row2)
    {
        printf("\nMultiplication not possible!\n");
        return 0;
    }
    printf("\nMultiplying the two matrix..\n");
    for(int i=0; i<row1; i++)
    {
        for(int j=0; j<col2; j++)
        {
            sum = 0;
            for(int k=0; k<col1; k++)
                sum = sum + mat1[i][k] * mat2[k][j];
            resmut[i][j] = sum;
        }
    }
    printf("resultant matrix is:\n");
    for(int i=0; i<row1; i++)
    {
        for(int j=0; j<col2; j++){
            printf("%d ", resmut[i][j]);
        }
        printf("\n");
    }
    return 0;
}