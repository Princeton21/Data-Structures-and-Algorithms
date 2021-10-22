  Binary search code in golang

package main
import "fmt"
  func main() {
          nums :=[]int{1,3,4,6,7,9,13,23,27,30}
          target := 23
          fmt.Println(search(nums,target))
  }
func search(nums []int, target int) int {
        low := 0
        high := len(nums) -1
        for low <= high {
        var mid = (high+low)/2
        if nums[mid] == target {
                   return mid
                   } else if nums[mid] > target {
                          high = mid - 1
                          } else {
                                   low = mid + 1
                                   }
                                 }
                         return (-1)
                 }
