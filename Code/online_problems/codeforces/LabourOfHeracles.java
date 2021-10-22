/*
Problem : 13th Labour of Heracles
Contest : Goodbye 2020
Question number : D
Link : https://codeforces.com/contest/1466/problem/D

Language : Java
*/


import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;



public class LabourOfHeracles {
    static void merge(int arr[][], int l, int m, int r)
    {
        int n1 = m - l + 1;
        int n2 = r - m;

        int L[][] = new int[n1][2];
        int R[][] = new int[n2][2];

        for (int i = 0; i < n1; ++i){
            L[i][1] = arr[l + i][1];
            L[i][0] = arr[l + i][0];

        }

        for (int j = 0; j < n2; ++j){
            R[j][1] = arr[m + 1 + j][1];
            R[j][0] = arr[m + 1 + j][0];

        }


        int i = 0, j = 0;

        int k = l;
        while (i < n1 && j < n2) {
            if (L[i][1] <= R[j][1]) {
                arr[k][1] = L[i][1];
                arr[k][0] = L[i][0];
                i++;
            }
            else {
                arr[k][1] = R[j][1];
                arr[k][0] = R[j][0];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k][1] = L[i][1];
            arr[k][0] = L[i][0];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k][1] = R[j][1];
            arr[k][0] = R[j][0];
            j++;
            k++;
        }
    }

    static void  sort(int arr[][], int l, int r)
    {
        if (l < r) {

            int m = (l + r) / 2;

            sort(arr, l, m);
            sort(arr, m + 1, r);

            merge(arr, l, m, r);
        }
    }
    public static void main(String[] args) {
        Scanner read = new Scanner(System.in);
        int t = read.nextInt();

        for (int i = 0; i < t; i++) {
            int n = read.nextInt();


            int[][] degrees = new int[n+1][2];

            for (int j = 0; j < n; j++) {
                degrees[j+1][1] = read.nextInt();
            }

            for (int j = 0; j < n-1; j++) {
                int x = read.nextInt();
                int y = read.nextInt();

                degrees[x][0]+=1;
                degrees[y][0]+=1;

            }

            sort(degrees , 0 , n);

            long count = 0;

//            for (int j = 0; j < n+1; j++) {
////                System.out.println(degrees[j][0] +" " + degrees[j][1]+ " hello");
//            }



            for (int j = 0; j < n+1; j++) {
                count = count + degrees[j][1];
            }
            int last = n;

            int sum = 0;

            System.out.print(count+ " ");



            while(sum!=n-2){
                if(degrees[last][0] > 1){

//                    System.out.println(degrees[last][1] + " last");

                    count = count+degrees[last][1];
                    System.out.print(count + " ");
                    degrees[last][0]--;
//                    System.out.println("degrees_last "+ degrees[last][0] + " of " + degrees[last][1]);
                    sum++;
                }
                else{
                    last --;
                }

            }

            System.out.println("");
        }
    }
}
