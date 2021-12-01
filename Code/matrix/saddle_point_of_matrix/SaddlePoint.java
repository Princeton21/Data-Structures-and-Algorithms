class SaddlePoint {
	public static void main(String[] args) {
		int matrix[][]= {{1, 2, 3},
						 {4, 5, 6},
						 {7, 8, 9}};
		int order = 3;
		if(findSaddlePoint(matrix,order) == false)
			System.out.println("No Saddle Point");
	}

	private static boolean findSaddlePoint(int[][] a, int n) {
		
		int k;
		// Process all rows one by one
		for(int i=0; i<n; i++) {
			int min_row = a[i][0], col_ind = 0;
			
			//Find the minimum row element and corresponding column
			for(int j=0; j<n; j++) {
				if(min_row > a[i][j]) {
					min_row = a[i][j];
					col_ind = j;
				}
			}
			
			// Check if the minimum element of row is also the maximum element of column or not
			for(k=0; k<n; k++) {
				if(min_row < a[k][col_ind])
					break;
				}
			
			// If saddle point is present in this row then print it
			if(k == n) {
				System.out.println("Value of Saddle Point " + min_row);
				return true;
			}
		}
		
		// If Saddle Point not found
		return false;
	}
}