# Linear Search

Linear search is the simplest search algorithm. It is a sequential search that starts at the first element of the array and goes through each element until the desired element is found.

### Steps for linear search
- Start from the leftmost element of the array and iterate through each element
- If the desired element is found, return its index
- If the end of the array is reached, return -1 (Not found)

### Pseudocode
```
LinearSearch(array, element) {
    for index=0 to length(array) {
        if array[index] = element {
            return index
        }
    }
    return -1
}
```
#### Time Complexity: O(n)
#### Space Complexity: O(1)