Searching algorithms by java

public class Linearsearch{

	static int search(int arr [],int target){
	  for (int i = 0; i <arr.length ; i++) {
             if(target==arr[i]){
                 return i;
             }
         }
         return -1;
     }

     public static void main(String[] args){
         int arr[]={5,12,78,34,21,9,1,2,4,7,8};
        int target=98;
        int result=search(arr,target);
     System.out.println(result);
    }
}
