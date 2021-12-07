package com.company;

import java.util.Scanner;

public class GCD {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int num1,num2;
        System.out.print("Enter the 2 numbers whose GCD is to be determined: ");
        num1=sc.nextInt(); //Inputting the 1st number
        num2=sc.nextInt(); //Inputting the 2nd number
        int greater;
        if(num1>num2)
            greater=num1;
        else
            greater=num2;
        int GCD=1; //Initializing the GCD variable
        for(int i=1;i<greater;i++){
            if((num1%i==0) && (num2%i==0)){
                GCD=i; //The GCD gets stored in the variable
            }
        }
        System.out.println("The Greatest Common Divisor of the inputted 2 numbers is: "+GCD); //Printing the Greatest Common Divisor
    }
}
