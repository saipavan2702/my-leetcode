func numIdenticalPairs(A []int) int {
    dict:=make(map[int]int)
    for _,v:=range A {
        dict[v]++
    }

    ans:=0
    for _,y:=range dict{
        ans+=((y*(y-1))/2)
    }
    return ans
}