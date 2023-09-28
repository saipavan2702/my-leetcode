func sortArrayByParity(A []int) []int {
    i,j,n:=0,0,len(A)
    for ;i<n;i++{
        if A[i]%2==0 {
            A[i],A[j]=A[j],A[i]
            j++;
        }
    }
    return A
}