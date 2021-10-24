import java.util.Arrays;

public class Shellsort {
	
	private int[] theArray;
	private int arraySize;
	
	Shellsort(int arraySize){
		this.arraySize = arraySize;
		theArray = new int[arraySize];
		generateRandomArray();
	}
	
	public void generateRandomArray() {
		// Generates random array values between 10 and 59 
		for(int i = 0; i < arraySize; i++)
			theArray[i] = (int)(Math.random()*50) + 10;
	}
	
	public static void main(String[] args) {
		Shellsort sort = new Shellsort(10);
        System.out.println("Unsorted Array: ");
		System.out.println(Arrays.toString(sort.theArray));
		sort.Sort();
        System.out.println("Sorted Array: ");
		System.out.println(Arrays.toString(sort.theArray));
	}
	
	public void Sort() {
		int inner, outer, temp;
		int interval = arraySize;
		
		// Continue the loop until the interval (outer- inner) is unity.
		while(interval > 0) {
				
			for(outer = interval; outer < arraySize; outer++) {	
				// Store the value of the array in temp unless it has to be copied to a space occupied by a bigger number from the interval distance of the array.
				temp = theArray[outer];
				inner = outer - interval;
					
				//If inner is greater then outer then swapping the values with themselves.
				if(theArray[inner] > temp) {
					theArray[outer] = theArray[inner];
					theArray[inner] = temp;
				}
				//printArray(inner, outer, interval);
			}
			interval = interval /2;
		}
	}
	
	/*
	 * public void printArray(int i, int j, int h) {
		if (i == j)
			i = i - h;
		
		for (int n = 0; n < 51; n++)
			System.out.print("-");
		System.out.println();
		
		for (int n = 0; n < arraySize; n++) 
			System.out.print("| " + n + "  ");
		System.out.println("|");
		
		for (int n = 0; n < 51; n++)
			System.out.print("-");
		System.out.println();
		
		for (int n = 0; n < arraySize; n++)
			System.out.print("| " + theArray[n] + " ");
		System.out.println("|");
		
		for (int n = 0; n < 51; n++)
			System.out.print("-");
		System.out.println();
		
		if (i != -1) {
			int spacesBeforeFront = 5 * i + 1;
			for (int k = 0; k < spacesBeforeFront; k++)
				System.out.print(" ");
			
			System.out.print("I");
			int spacesBeforeRear = (5 * j + 1 - 1) - spacesBeforeFront;
			for (int l = 0; l < spacesBeforeRear; l++)
				System.out.print(" ");
			System.out.print("O");
			System.out.println("\n");
		}
	}
	*/
	
}