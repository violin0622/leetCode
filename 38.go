package main
import "strconv"

var testcase = []string{
    "1",
    "11",
    "21",
    "1211",
    "111221",
    "312211",
    "13112221",
}

func countAndSay(n int) string {
    if n== 0{
        return ""
    }
    lastStr := "1"
    str := ""
    for i:=1; i<n; i++{
        prev := lastStr[0]
        current := lastStr[0]
        count := 0
        for i:=0; i<len(lastStr); i++{
            current = lastStr[i]
            if current != prev {
                str += strconv.Itoa(count) + string(prev)
                count = 0
            }
            count ++
            prev = current
        }
        str += strconv.Itoa(count) + string(current)
        lastStr, str = str, ""
    }
    return lastStr
}

func main(){
    for index, str := range testcase{
        println(index+1, str, countAndSay(index+1))
    }
}
