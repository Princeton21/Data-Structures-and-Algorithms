# This is the implementation of bubble sort in python.
# The time complexity of the algorithm is O(n^2), and the space complexity is O(1).

def bubbleSort(l,arr):
	# Here, the argument l is the length of the array
	# And the argument arr is the array which has to be sorted.

	for i in range(l):
		for j in range(0,l-i-1):
			if(arr[j] > arr[j+1]):
				temp = arr[j]
				arr[j] = arr[j+1]
				arr[j+1] = temp