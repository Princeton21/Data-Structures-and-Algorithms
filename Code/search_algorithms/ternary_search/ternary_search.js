const ternarySearch = (l, r, key, arr) => {
	if (r >= l) {
		// Find the mid1 and mid2
		const mid1 = Math.floor(l + (r - l) / 3)
		const mid2 = Math.floor(r - (r - l) / 3)

		// Check if key is present at any mid
		if (arr[mid1] == key)
			return mid1
		
		if (arr[mid2] == key)
			return mid2

		if (key < arr[mid1])
			return ternarySearch(l, mid1 - 1, key, arr)
		else if (key > arr[mid2])
			return ternarySearch(mid2 + 1, r, key, arr)
		else
			return ternarySearch(mid1 + 1, mid2 - 1, key, arr)
    }
	return -1  // Key not found
};

// Get the array
// Sort the array if not sorted
const arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

const l = 0  // Starting index
const r = arr.length  // length of array

// Checking for 5
key = 5  // Key to be searched in the array

// Search the key using ternarySearch
let p = ternarySearch(l, r, key, arr)

// Print the result
console.log("Index of", key, "is", p)

// Checking for 50
key = 50

// Search the key using ternarySearch
p = ternarySearch(l, r, key, arr)

// Print the result
console.log("Index of", key, "is", p)
