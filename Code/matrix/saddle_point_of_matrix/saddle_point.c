// C program to find the saddle point coordinates in the given matrix
#include <stdio.h>
int main()
{
	int i, j, k, m, n, min, max,pos[2][2];
	/* Input the size of the matrix from the user */
	printf("Enter the square matrix order : ");
	scanf("%d", &m);
	int matrix[m][m];
	/* Input the matrix */
	printf("\nInput the matrix : ");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}
	printf("\nThe matrix is \n");
	for (i = 0; i < m; i++)
		{
			for (j = 0; j < m; j++)
				{
					printf("%d ", matrix[i][j]);
				}
			printf("\n");
		}
/* find the saddle points in the given matrix */
	for (i = 0; i < m; i++)
		{
			min = matrix[i][0];
			for (j = 0; j < m; j++)
				{
					if (min >= matrix[i][j])
						{
							min = matrix[i][j];
							pos[0][0] = i;
							pos[0][1] = j;
						}
				}
     j = pos[0][1];
     max = matrix[0][j];
	for (k = 0; k < m; k++)
	{
		if (max <= matrix[k][j])
			{
				max = matrix[i][j];
				pos[1][0] = k;
				pos[1][1] = j;
			}
	}
/* saddle point is the minimum of a row and maximum of the column */
	if (min == max) 
    {
		if (pos[0][0] == pos[1][0] &&pos[0][1] == pos[1][1])
		{
			printf("\nSaddle point (%d, %d) : %d",pos[0][0], pos[0][1], max);
		}
	}
}
	return 0;
}
