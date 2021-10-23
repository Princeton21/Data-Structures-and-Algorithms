import java.util.Scanner;

public class HourglassPattern {

    static void pattern(int rows_no) {
        int i, j, k;

        // for loop for printing
        // upper half
        for (i = 1; i <= rows_no; i++) {

            for (k = 1; k < i; k++)
                System.out.print(" ");

            for (j = i; j <= rows_no; j++)
                System.out.print(j + " ");

            System.out.println();
        }

        // for loop for printing lower half
        for (i = rows_no - 1; i >= 1; i--) {

            for (k = 1; k < i; k++)
                System.out.print(" ");

            for (j = i; j <= rows_no; j++)
                System.out.print(j + " ");

            System.out.println();
        }
    }

    // Driver code
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int rows = sc.nextInt();

        pattern(rows);
        sc.close();

    }
}
