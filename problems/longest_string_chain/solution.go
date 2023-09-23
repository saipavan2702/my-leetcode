func longestStrChain(words []string) int {
    sort.Slice(words,func (i,j int) bool{
        return len(words[i])<len(words[j])
    })

    dp:=make(map[string]int)
    ans:=1
    for _,val:=range words{
        dp[val]=1
        for i:=0;i<len(val);i++{
            ref:=val[:i]+val[i+1:]
            if cnt,has:=dp[ref]; has {
                dp[val] = Max(dp[val],cnt+1)
            }
        }
        ans= Max(dp[val],ans)
    }
    return ans
}

func Max(x,y int)int{
    if x>y {return x}

    return y
}