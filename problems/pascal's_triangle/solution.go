func generate(R int) [][]int {
    var dp [][]int
    if R==0 {
        return dp
    }

    dp=append(dp,[]int{1})
    for i:=1;i<R;i++ {
        var curr []int
        curr=append(curr,1)
        for j:=1;j<i;j++ {
            curr=append(curr,dp[i-1][j-1]+dp[i-1][j])
        }
        curr=append(curr,1);
        dp=append(dp,curr)
    }
    return dp

}