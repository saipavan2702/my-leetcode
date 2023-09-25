func findTheDifference(s string, t string) byte {
    dp:=make([]int,26);
    for _,x:=range s{
        dp[int(x)-97]++
    }

    for _,x:=range t{
        dp[int(x)-97]--;
    }

    for i:=0;i<26;i++ {
        if dp[i]!=0 {
            return byte(i+97)
        }
    }
    return '1'
}