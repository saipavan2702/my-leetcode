func isMonotonic(A []int) bool {
    h,n:=0,len(A)
    for i:=1;i<n;i++ {
        if A[i]>A[i-1] {
            if h==0 {
                h=1
            }else if h==-1{
                return false
            }
        }else if A[i-1]>A[i] {
            if h==0 {
                h=-1
            }else if h==1 {
                return false
            }
        }
    }
    return true
}
