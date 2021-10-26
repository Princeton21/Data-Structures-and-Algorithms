#include <stdio.h>

/*Shell sort algorithm */
void Shell_sort(int A[], int size) {
	int i, j, h, v;
	for (h=1; h=size/9; h=3*h+1) {
		for( ; h>0; h=h/3) {
			for (i=h+1; i<size; i+=1) {
				v = A[i];
				j =i;
				while (j>h && A[j-h]>v) {
					A[j] = A[j-h];
					j-=h;
				}
				A[j]=v;
			}
		}
	}
}

/* Print an array */
void print_array(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
	int data[] = {7, 9, 3, 8, 5, 6, 4, 1};
  	int size = sizeof(data) / sizeof(data[0]);
  	shellSort(data, size);
  	printf("Sorted array: \n");
  	print_array(data, size);
	return 0;
}
