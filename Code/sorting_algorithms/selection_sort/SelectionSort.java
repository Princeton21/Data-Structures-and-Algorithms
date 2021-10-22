class SelectionSort{
	public static void main(String[]args){
		int[] a = {6,4,3,8,7,9,2,24,89,43,1,80,54};

		int min=0;
		int temp=0;
		for(int i=0; i<a.length-1; i++){
			min = a[i];
			for(int j=i; j<a.length; j++){
				if(min>a[j]){
					temp = a[i];
					a[i] = a[j];
					a[j] = temp; 
				}
			}
		}

		for(int i=0; i<a.length; i++){
			System.out.println(a[i]);
		}
	}
}