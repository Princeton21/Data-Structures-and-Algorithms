# @description: This is the implementation of bubble sort in python.
# @param arr: an array of numbers to be sorted.
# @returns: array sorted from low to high.
# The time complexity of the algorithm is O(n^2), and the space complexity is O(1).

def bubbleSort(arr):
    completed = False
    while not completed:
        changed = False
        i = 0
        for i in range(len(arr)-1):
            if(arr[i] > arr[i+1]):
                changed = True
                temp = arr[i]
                arr[i] = arr[i+1]
                arr[i+1] = temp
            i+=1
        if(changed == False):
            completed = True
    return arr

list = [5,4,3,2,1,3,5,2,123,56216,634,6,34] # Test Case
print(bubbleSort(list))
