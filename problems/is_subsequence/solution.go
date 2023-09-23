func isSubsequence(s string, t string) bool {
    i,j:=0,0
    n,p:=len(s),len(t)

    for ;i<p && j<n;i++ {
        if s[j]==t[i] {
            j++
        }
    }

    return j==n
}