#include<stdio.h>
int main()
{
	int n;
	printf("Enter no of rows or columns:");//user can give the no of rows
	scanf("%d",&n);
	int a[n][n];//transpose of matrice can only perform on square matrices
	int i,j,temp;
	printf("Enter values for matrix:\n");
		for(i=0;i<n;i++)//giving values by user
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i<j)
			{
		     	temp=a[i][j];
			    a[i][j]=a[j][i];    //swaping values if i<j and i=j values be at same position
			    a[j][i]=temp;
			}	
		}
	}
	printf("transpose of a matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",a[i][j]);
		}
			printf("\n");
	}
 return 0;


/*
example for 3x3 matrice:
Enter no of rows or columns:3
1
2
3      //1 2 3   1 4 7
4     //4 5 6 => 2 5 8
5    //7 8 9     3 6 9
6
7
8
9
Transpose of the matrice:
1 4 7
2 5 8
3 6 9*/		
}
