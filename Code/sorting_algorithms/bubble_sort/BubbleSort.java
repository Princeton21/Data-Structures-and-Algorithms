class BubbleSort{
	public static void main(String[]args){
		int[] a={67,45,789,23,46,123,56,43,90,78};
		int z=0;
		int temp=0;
		int x=0;
		while(x <= a.length){
			
			int n = 9;
			
			for(int i=1; i<=n; i++){

				if(a[z]>a[z+1]){
					temp = a[z+1];
					a[z+1] = a[z];
					a[z] = temp;
				}
				z+=1;
			}
			x++;
			c++;
			z=0;
		}

		for(int i=0; i<a.length; i++){
			System.out.println(a[i]);
		}
	}
}