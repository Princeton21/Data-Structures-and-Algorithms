//transpose in matrix

public class Transpose {

     static int[][] transpose(int arr [][]) {
         int r= arr.length;
         int c=arr[0].length;
         int transpose[][]=new int[c][r];
         for (int row = 0; row < arr.length ; row++) {
             for (int col = 0; col <arr[row].length ; col++) {
                 transpose[col][row]=arr[row][col];
             }
         }
     return transpose;
     }
    public static void main(String[] args){
         int arr[][]={
                 {1,2,3},
		 {4,5,6},
                 {7,8,9},
         };
        int result[][]= transpose(arr);
     System.out.println(Arrays.deepToString(result));
    }
}

