list = [1,2,3,4,5,6,7,8,9,10]
def binarySearch(list,target):
    result = None
    while (result != target):
        midPoint = list[int(len(list)/2)-1]
        if(target > midPoint):
            list = list[midPoint:]
        else:
            list = list[:midPoint-1]
        result = midPoint
    return result

print(binarySearch(list,1))