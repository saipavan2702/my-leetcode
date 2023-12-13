func numSpecial(G [][]int) int {
    n,p:=len(G),len(G[0])
    R:=make([]int,n)
    C:=make([]int, p)

    for i:=0;i<n;i++ {
        for j:=0;j<p;j++ {
            if G[i][j]==1 {
                R[i]++
                C[j]++
            }
        }
    }

    ans:=0
    for i:=0;i<n;i++ {
        for j:=0;j<p;j++ {
            if G[i][j]==1 && R[i]==1 && C[j]==1 {
                ans++
            }
        }
    }
    return ans

}