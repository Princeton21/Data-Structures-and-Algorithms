#Bucket Sort is a linear time sorting algorithm, It is used when input is distributed uniformly over the interval [0, 1)
#It sorts the input following the above condition in linear time otherwise it takes quadratic time to sort the array.
#This algorithm makes use of insertion sort to sort individual buckets.

def insertionSort(arr):
	for i in range(1, len(arr)):
		key = arr[i]
		j = i-1
		while j >=0 and key < arr[j] :
				arr[j+1] = arr[j]
				j -= 1
		arr[j+1] = key
        
def BucketSort(arr):
    n=len(arr)
    Buckets = [[] for i in range(n)] #Creating buckets
    
    #Filling the buckets
    for i in arr:
        Buckets[int(i*n)].append(i)
    
    sol=[] #Solution array
    for i in range(n):
        insertionSort(Buckets[i]) #Sorting individual buckets with insertion sort
        sol+=Buckets[i] #Appending sorted buckets in the solution buckets
    
    return sol

arr=[0.1,0.7,0.4,0.8,0.2,0.6,0.9,0.3,0.5] #Test Data
print(BucketSort(arr))