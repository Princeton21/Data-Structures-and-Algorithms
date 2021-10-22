/*
 Contest : CodeChef Starters 14
 Problem :ODD GCD
 Problem code : BININVER
 Contest : CodeChef Starters 14
 Link: https://www.codechef.com/problems/BININVER

*/
  

import java.util.*;
import java.lang.*;
import java.io.*;


public class OddGCD
{
	public static void main (String[] args) throws java.lang.Exception
	{
		
		long[] arr;
		int t;
		long n;
		Scanner sc = new Scanner(System.in);
		t= sc.nextInt();
		sc.nextLine();
		
		while(t-->0){

		      n= sc.nextLong();
		      arr= new long[(int)n];
		    
		    long enumber=0, onumber=0;
		    
		      for(int i=0; i<n; i++)
		      {
		              arr[i]= sc.nextLong();
		              
		              if(arr[i]%2==0)
		                enumber++;
		             else
		              onumber++;
		      }
		      
		      if(enumber==n){
		            long res= 1000000000;
		            
		            for(int i=0; i<n; i++){
		                  long ans=0;
		                  
		                  while(arr[i]%2!=1)
		                     {
		                           arr[i]=arr[i]/2;
		                           ans++;
		                     }
		                     
		                     if(ans<res)
		                      res=ans;
		                      
		            }
		            
		            System.out.println(res);
		      }
		    else
		    System.out.println(0);
		   
		}
	}
}
