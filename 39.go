package main
import (
    "fmt"
    "sort"
    "reflect"
)
func combinationSum(candidates []int, target int) [][]int {
    results := [][]int{}
    sequence := []int{}
    sort.Ints(candidates)
    sum(target, sequence,0, &results, &candidates)
//    for _,slice := range results{
//        fmt.Println(slice)
//    }
    return results
}

var depth = 0
func sum(target int, sequence []int, index int, results *[][]int, candidates *[]int){
    depth += 1
    if target < 0{
        return
    } else if target == 0 {
        addResult(results, sequence)
        return
    }else{
        for i:=index; i<len(*candidates); i++{
            num := (*candidates)[i]
            //sequence = append(sequence, num)
            sum(target-num, append(sequence,num), i, results, candidates)
            //sequence = sequence[:len(sequence)-1]
        }
    }
}

func addResult(results *[][]int , sequence []int){
    sort.Ints(sequence)
    for _,slice := range *results{
        if reflect.DeepEqual(slice, sequence) {
            return
        }
    }
    result := make([]int, len(sequence))
    copy(result, sequence)
    *results = append(*results, result)
}

func main(){
    candidates := []int{2,3,7}
    combinationSum(candidates, 18)
}
