public class Reverse_Array_in_Java {

  

   public static void main(String []args) {                  //Main Function
      int[] arr = { 2,5,42,5,43,21};                        // Initializing Array arr 
      int n = arr.length;                                   // Storing length of Array arr in variable n
      int l = 0;                                            // initializing a counter l for later use   
      
      System.out.println("Original Array");

      for(int i = 0; i< n ; i++){                           // for loop for printing array arr       
      System.out.println(arr[i]);
      }

      int[] arr_reverse = new int[n];                       // initializing another array arr_reverse with length  same as that of original array  

      for(int j = n-1; j >= 0;j--){                           // for loop for filling arr_reverse 
         arr_reverse[l] = arr[j];                              // the pointer j initializes at the end of arr and moves backward across each element
         l++;                                                  // Thus storing each element of the first array in the second one in reverse.
      }


      System.out.println("Original Array in reverse");

      for(int i = 0; i< n ; i++){                              // for loop for printing array arr_reverse
      System.out.println(arr_reverse[i]);
      }




   }
}