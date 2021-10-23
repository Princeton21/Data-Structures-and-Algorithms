class Solution {
    public int[][] transpose(int[][] matrix) {
        int row,col,i,j;
        row=matrix.length;
        col=matrix[0].length;
        int[][] trans=new int[col][row];
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                trans[j][i]=matrix[i][j];
            }
        }
        return trans;
    }
}
