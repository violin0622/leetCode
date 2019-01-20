package main
import (
    "fmt"
)

func removeElement(nums []int, val int) int {
    i, j := 0, 0
    for ;j<len(nums); j++ {
        if nums[j] == val {
            continue
        }
        nums[i] = nums[j]
        i++
    }
    return len(nums) - (j-i)
}

func main(){
    s := []int{3,1,2,3}
    sl := make([]int, 2,2)
    sl = s
    for index, value := range sl{
        fmt.Println(index, value)
    }
    fmt.Println(removeElement(s, 3))
}
