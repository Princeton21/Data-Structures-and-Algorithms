package com.company;
import java.io.*;
import java.lang.*;
import java .util.*;

public class array_insertion {
    public static void insertion(int size_n, int array[], int element, int position){
        int incremented_array[]= new int[size_n+1];
        for(int i=0;i<=size_n;i++){
            if(i==(position-1))
                incremented_array[i]=element; //Inserts the element when index of the new incremented
                                             //array matches our desired position of insertion
            else if(i<(position-1))
                incremented_array[i]=array[i];

            else
                incremented_array[i]=array[i-1]; // i-1 because the size of the array has increased
                                               // by 1 after inserting an element
        }
        for(int i=0;i<=(size_n+1);i++){
            System.out.print(incremented_array[i]+" "); // This prints the array after insertion
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of array: ");
        int n=sc.nextInt(); //Taking the size of array from user
        int arr[]=new int[100]; //declaring an array "arr" having 100 memory length
        System.out.println("Enter the elements of array: ");
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();//inputting elements into the array
        }
        //Displaying the array

        System.out.println("Array before insertion is: ");
        for(int i=0;i<n;i++){
            System.out.println(arr[i]+" ");//Space is added to display array neatly
        }
        System.out.println("Array after insertion is: ");
        insertion(n,arr,12,3);


    }
}
