class InsertionSort{
	public static void main(String[]args){
		int[] a={56,45,21,45,74,63,214,124,157,478,1256,4215,74,4};

		int z = 0;
		int j = 0;
		int temp = 0;

		while(z<(a.length-1)){
			if (a[z]> a[z+1]){   // z=0
				temp = a[z+1];   //temp = 45
				a[z+1] = a[z];	 //a[1] = 56
				a[z] = temp;	//a[0] = 45
				j = z;

				while(j>0){
					if (a[j-1]>a[j]){
						temp = a[j-1];
						a[j-1] = a[j];
						a[j] = temp;
					}
					j--;
				}	
			}
			z++;
		}

		for (int i=0; i<a.length; i++){
			System.out.println(a[i]);
		}
	}
}