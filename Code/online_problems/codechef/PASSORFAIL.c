/*
 Contest : CodeChef Starters 16C
 Problem : Pass or Fail
 Problem code : PASSORFAIL
 Link: https://www.codechef.com/START16C/problems/PASSORFAIL
*/

#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	for (int i = 0; i < t; i++) {
	    int n,x,p,s;
	    scanf("%d %d %d",&n,&x,&p);
	    s = x*3 - n + x;
	    if (s>=p) {
	        printf("PASS\n");
	    }
	    else {
	        printf("FAIL\n");
	    }
	}
	return 0;
}
