#Python does not have built-in support for Arrays, but Python Lists can be used instead.
import random

#Function to create an array of len_arr elements
def create_arr(len_arr):
  arr=[]
  for item in range(len_arr):
    #random value from 0 to 99 inclusive
    x = random.randrange(100)
    arr.append(x)
  return arr

#Implementation of reverse an array just by swaping index
#in a new array, from the index len-1 to 0 inclusive
def reverse_array(arr):
  ret=[]
  for i in range(len(arr)-1,0-1,-1):
    ret.append(arr[i])
  return ret

len_arr=15
arr = create_arr(len_arr)

print("Array before reversed\n",arr)
print("Array after reversed\n",reverse_array(arr))

arr.reverse()
print("Python list.reversed() to check that everything is OK\n",arr)


