func getSumAbsoluteDifferences(A []int) []int {
    n:=len(A)
    acc:=0
    for i:=0;i<n;i++ {
        acc+=A[i]
    }
    L:=0
    for i,val:=range A{
        A[i]=acc-val*(n-i)+(val*i)-L
        L+=val
        acc-=val
    }
    return A
}