package main

import(
    "sort"
    "fmt"
)

func combinationSum2(candidates []int, target int) [][]int {
    results := [][]int{}
    combo := []int{}
    sort.Ints(candidates)
    dfs(&results, target, combo, candidates)
    return results
}

func dfs(results *[][]int, target int, combo []int, list []int){
    if target==0{
        result := make([]int, len(combo))
        copy(result, combo)
        *results = append(*results, result)
        return
    }
    if target<0{
        return
    }
    for index, num := range list{
        if index>0 && list[index-1] == num{
            continue
        }
        dfs(results, target-num, append(combo,num), list[index+1:])
    }
}

func main(){
    //candidates := []int{10,1,2,7,6,1,5}
    candidates := []int{3,1,3,5,1,1}
    fmt.Println(combinationSum2(candidates, 8))
}
