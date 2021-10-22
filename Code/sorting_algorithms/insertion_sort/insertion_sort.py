#Python Program for insertion sort. Time complexity - O(n^2)

def insertionSort(arr):
	for i in range(1, len(arr)):
		key = arr[i]
		j = i-1
		while j >=0 and key < arr[j] :
				arr[j+1] = arr[j]
				j -= 1
		arr[j+1] = key


arr = [12, 11, 13, 5, 6, 45, 23]
insertionSort(arr)
print ("Sorted array:", end=" ")
for i in range(len(arr)):
	print ("%d" %arr[i], end=" ")

