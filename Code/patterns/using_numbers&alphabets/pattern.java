import java.util.Scanner;

 class Pattern{
    public static void main(String[] args){
        Scanner scn = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = scn.nextInt();
        for(int i=1; i<=n; i++){
            int k=1;
            for(int j=n-i;j>=1; j-- )
                System.out.print("  ");
            for(int j=1; j<2*i; j++){
                System.out.print(k+" ");
                if(j<i)
                    k++;
                else
                    k--;
            }
            System.out.println();
        }

    }
}
