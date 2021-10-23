const binarySearch = (arr, l, r, x) => {
    if (r >= l) {
        mid = l + (r - l) / 2
 
        if (arr[mid] == x)
            return mid
 
        if (arr[mid] > x)
            return binarySearch(arr, l, mid-1, x)
 
        return binarySearch(arr, mid+1, r, x)
    }
    return -1
};

const exponentialSearch = (arr, x) => {
    n = arr.length
    if (arr[0] == x)
        return 0

    i = 1
    while (i < n && arr[i] <= x)
        i *= 2
 
    return binarySearch(arr, i/2, Math.min(i, n-1), x)
};

arr = [1, 3, 4, 10, 40]
x = 10
result = exponentialSearch(arr, x)

console.log("Element is", result === -1 ? "not present in array": `present at index ${result}`)
