#Doing linear seach in array with O(n) time complexity

def search(arr, x):
    length = len(arr)
    for i in range(length):
        if arr[i] == x:
            return i
    return -1
	


arr = [2,6,3,8,54,23,45]
search_element = 45
found = search(arr, search_element)
if(found!=-1):
    print("Element Found at Position - {}".format(found))
else:
    print("Element is not found")
    
