target = int(input("enter search target: "))
def binarySearch(list,target):
    maximum = len(list) -1
    minimum = 0
    result = None
    while (result != target):
        m = (maximum + minimum) // 2
        midPoint = list[m]
        if(target > midPoint):
            minimum = m +1
        elif(target < midPoint):
            maximum = m -1
        else:
            return m
        result = midPoint
    return m
print(binarySearch([1,2,3,4,5,6,7,8,9,10],target))