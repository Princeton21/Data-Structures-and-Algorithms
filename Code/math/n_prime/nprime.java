import java.util.Scanner;

class uprime{
	public static void main(String args[]){
	Scanner sc = new Scanner(System.in);
	System.out.println("Enter number till where you want to print prime numbers");
	int num = sc.nextInt();
	System.out.println("Prime numbers upto "+num +" are :");
	int x=2;
	while(x<num){
	int flag=1;
	for( int i=2;i<x;i++){
		if(x%i==0){
		flag=0;
		break;
		}
	}
	if(flag==1){
	System.out.print(x +" ");
	}
	x++;
	}
	
}}