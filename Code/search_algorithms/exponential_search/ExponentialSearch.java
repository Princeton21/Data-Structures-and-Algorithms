import java.util.Scanner;

public class ExponentialSearch {
    private static int binarySearch(int[] array, int startIndex, int endIndex, int numberToFind) {
        if ((startIndex <= endIndex)) {
            int middleIndex = startIndex + (endIndex - startIndex) / 2;
            if (array[middleIndex] == numberToFind) {
                return middleIndex;
            } else if (array[middleIndex] > numberToFind) {
                return binarySearch(array, startIndex, middleIndex - 1, numberToFind);
            } else {
                return binarySearch(array, middleIndex + 1, endIndex, numberToFind);
            }
        }
        return -1;
    }

    private static int exponentialSearch(int numberToFind, int[] array, int sizeOfArray) {
        if (array[0] == numberToFind) {
            return 0;
        }
        int index = 1;
        while ((index < sizeOfArray) && (array[index] <= numberToFind)) {
            index *= 2;
        }
        return binarySearch(array, (index / 2), Math.min(index, sizeOfArray - 1), numberToFind);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the size of the array : ");
        int sizeOfArray = scanner.nextInt();
        int[] array = new int[sizeOfArray];
        System.out.print("Enter the sorted array elements separated by spaces : ");
        for (int index = 0; index < sizeOfArray; index++) {
            array[index] = scanner.nextInt();
        }
        System.out.print("Enter the number to search : ");
        int numberToSearch = scanner.nextInt();

        int foundAtIndex = exponentialSearch(numberToSearch, array, sizeOfArray);

        if (foundAtIndex >= 0) {
            System.out.println("The number " + numberToSearch + " found at index " + foundAtIndex);
        } else {
            System.out.println("The number " + numberToSearch + " is not present in the array");
        }
        scanner.close();
    }
}

