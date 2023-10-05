func majorityElement(A []int) []int {
    dp:=[]int{}
    dict:=make(map[int]int)
    for _,v:=range A{
        dict[v]++;
    }

    for x,y:=range dict{
        if y>len(A)/3 {
            dp=append(dp,x)
        }
    }
    return dp;
}