// Matrix multiplication


public class  MatrixMultiplication {

     static int[][] matrix(int arr [][],int [][] arr1) {
         int row1= arr.length;
         int row2= arr1.length;
         int col1=arr[0].length;
         int col2=arr1[0].length;
        int ans[][]=new int[row1][col2];
         for (int i = 0; i < row1; i++) {
             for (int j = 0; j < col2; j++) {

                 for (int k = 0; k < row2; k++) {
                     ans[i][j]+=arr[i][k]*arr1[k][j];
                 }
             }
         }
         return ans;
     }
    public static void main(String[] args){
         int arr[][]={
                 {3,4},
                 {2,1},

         };
        int arr1[][]={
                {1,5},
                {3,7},
        };

        int result[][]= matrix(arr,arr1);
     System.out.println(Arrays.deepToString(result));
    }
}
