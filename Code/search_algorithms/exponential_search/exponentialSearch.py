def binarySearch(ar, l, r, x):
    if r >= l:
        mid = int(l + (r - l) / 2)
        if ar[mid] == x:
            return mid
        if ar[mid] > x:
            return binarySearch(ar, l, mid - 1, x)
        return binarySearch(ar, mid + 1, r, x)
    return -1


def exponentialSearch(ar, n, x):
    if ar[0] == x:
        return 0
    i = 1
    while i < n and ar[i] <= x:
        i = i * 2
    return binarySearch(ar, i / 2, min(i, n - 1), x)


ar = [2, 3, 4, 10, 40]
n = len(ar)
x = 10
result = exponentialSearch(ar, n, x)
if result == -1:
    print("Element not the array")
else:
    print(str(x) + " is at index %d" % result)
