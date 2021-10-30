/*
Problem : New Colony
Contest : Division 2 699
Question number : B
Link : https://codeforces.com/contest/1481/problem/B

Language : Java
*/


import java.util.Scanner;

public class NewColony {
    public static void main(String[] args) {
        Scanner read = new Scanner(System.in);
        int t = read.nextInt();

        for (int i = 0; i < t; i++) {
            int n = read.nextInt();
            int k = read.nextInt();
            int[] arr = new int[n];
            for (int j = 0; j < n; j++) {
                arr[j]= read.nextInt();
            }
            int pos = 0;
            while(k>0 && pos < n-1){
                if(arr[pos]<arr[pos+1]){
                    arr[pos]++;
                    k--;
                    if(k!=0){
                        pos = 0;
                    }
                    else{
                        break;
                    }
                }
                else{
                    pos++;
                }

            }
            if(k!=0 && pos == n-1){
                System.out.println(-1);
            }
            else{
                System.out.println(pos+1);
            }
        }
    }
}
