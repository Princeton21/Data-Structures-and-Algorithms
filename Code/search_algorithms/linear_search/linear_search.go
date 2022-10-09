package main

import "fmt"

type int_array []int

func (arr int_array) lin_search(ele int) int {
	for i, n := range arr {
		if n == ele {
			return i
		}
	}
	return -1
}

func main() {
	var size int
	fmt.Print("Enter the size of the array: ")
	fmt.Scanf("%d", &size)
	fmt.Printf("\n")

	arr := make(int_array, size)
	fmt.Println("Enter the elements of the array:")
	for i := 0; i < size; i++ {
		fmt.Scanf("%d", &arr[i])
	}
	fmt.Printf("\n")

	var ele int
	fmt.Print("Enter the element to be searched: ")
	fmt.Scanf("%d", &ele)
	fmt.Printf("\n")

	pos := arr.lin_search(ele)
	if pos < 0 {
		fmt.Println(ele, "is not present in the array")
	} else {
		fmt.Println(ele, "is present at position", pos)
	}
}
