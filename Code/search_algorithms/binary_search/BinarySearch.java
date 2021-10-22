class BinarySearch{
	public static void main(String[]args){
		int[] a = {10,17,23,25,26,32,45,47,56,60};
		int top=0;  //l
		int middle,bottom,searchV = 0;
		boolean x=true;
		searchV = 45;   //e
		bottom = 9; //r
		middle = (top+bottom)/2;    // middle = 4.5 -> 4 -> 26
		

		while(x){
			if(searchV==a[middle]){
				System.out.println(middle);
				x=false;
				break;
			}
			if(searchV<a[middle]){
				top=top;
				bottom=middle-1;
				middle=(top+bottom)/2;  // 5 -> 
			}
			if(searchV>a[middle]){
				top=middle+1;  // 5 ->32
				bottom=bottom;
				middle=(top+bottom)/2;  // 7 -> 47
			}
			x=true;
		}
	}
}