public class Program {


	static void rotate90Clockwise(int a[][])
{
	if (a == null||a[0] == null||a.length != a[0].length)return;
	int N = a.length;
    // Traverse each cycle
    for (int i = 0; i < N / 2; i++)
    {
        for (int j = i; j < N - i - 1; j++)
        {
            // Swap elements of each cycle
            // in clockwise direction
            int temp = a[i][j];
            a[i][j] = a[N - 1 - j][i];
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
            a[j][N - 1 - i] = temp;
        }
    }
}
// Function for print matrix
static void printMatrix(int a[][])
{
	if (a == null||a[0] == null||a.length != a[0].length)return;
	int N = a.length;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        System.out.print( a[i][j] + " ");
        System.out.println();
    }
}

    public static void main (String[] args)
    {
            int arr[][] = { { 1, 1, 1, 2 },
                      { 1, 1, 1, 2 },
                      { 1, 1, 1, 2 },
                      { 1, 1, 1, 2 } };
    rotate90Clockwise(arr);
    printMatrix(arr);
    }
}

