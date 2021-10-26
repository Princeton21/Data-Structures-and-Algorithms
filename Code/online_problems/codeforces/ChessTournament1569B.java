/*
Problem : Chess Tournament
Contest : Educational Codeforces Round 113 (Rated for Div. 2)
Question number : 1569 B
Link : https://codeforces.com/contest/1569/problem/B

Language : Java
*/

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		int t = scan.nextInt();
		while(t-->0) {

			int n = scan.nextInt();
			String s = scan.next();
			int count = 0;
			List<Integer> two = new ArrayList<Integer>();
			String arr[][] = new String[n][n];

			for(int i=0; i<n; i++) {
				int val = (int)s.charAt(i)-48;
				if(val==1) {
					for(int j=0; j<n; j++)
						arr[i][j]="=";
					for(int  k=0; k<n; k++)
						arr[k][i]="=";
				}
				else 
					two.add(i);
			}
			for(int j=0; j<n; j++)
				arr[j][j] = "X";
			for(int j=0; j<n; j++) {
				for(int k=0; k<n; k++)
					if(arr[j][k]==null)
						count++;
			}

			if(count<two.size()*2) {
				System.out.println("NO");
				continue;
			}
			
			if(two.size()>0) {
				for(int i=0; i<two.size(); i++) {
					int plus = 0;
					int nullval = 0;
					for(int k=0; k<n; k++) {
						if(arr[two.get(i)][k] == null) {
							if(nullval==0) {
								nullval = k;
							}
							arr[two.get(i)][k] = "-";
							arr[k][two.get(i)] = "+";
						}
						else if(arr[two.get(i)][k].equals("+"))
							plus++;
					}
					if(plus==0) {
						arr[two.get(i)][nullval]="+";
						arr[nullval][two.get(i)]="-";
					}
				}
			}
			System.out.println("YES");
			
            for(int j=0; j<n; j++) {
				for(int k=0; k<n; k++) 
					System.out.print(arr[j][k]);
				System.out.println();
			}
            
		}
	}
}