func Max(x, y int) int {
	if x < y {
		return y
	}
	return x
}
func minOperations(v []int, x int) int {
    n:=len(v)
    i,j,need:=0,0,0
    for _,val:=range v {
        need+=val
    }
    need-=x
    if need==0{return n}
    len,curr:=0,0

    for ;i<n;i++ {
        curr+=v[i]
        for j<=i && curr>need{
            curr-=v[j]
            j++
        }
        if curr==need{
            len=Max(len,i-j+1);
        }
    }
    if len==0{return -1}
    return n-len
}