#include <stdio.h>
#include<time.h>

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void insertionSort(int array[], int size) {
  for (int b = 1; b < size; b++) {
    int key = array[b];
    int j = b - 1;

    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}


int main() {
  int data[] = {9, 5, 1, 4, 3};
  int size = sizeof(data) / sizeof(data[0]);
  clock_t t; 
	t = clock(); 
  insertionSort(data, size);
  printf("Sorted array in ascending order:\n");
  printArray(data, size);
  double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 

	printf("fun() took %f seconds to execute \n", time_taken); 
}