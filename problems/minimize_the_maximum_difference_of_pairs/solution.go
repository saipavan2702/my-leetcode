func check(A[] int, u int, p int) bool {
    cn,n:=0,len(A)
    for i:=0;i<n-1;i++{
        if(A[i+1]-A[i]<=u){
            cn++
            if(cn>=p){
                return true
            }
            i++;
        }
    }
    return false
}

func minimizeMax(A []int, p int) int {
    sort.Ints(A)
    n,ans:=len(A),0

    if(p==0){
        return 0
    }
    lo,hi:=0,A[n-1]-A[0]
    for lo<=hi{
        u:=(lo+hi)/2
        // for i:=1;i<n-1 && cn<p; {
        //     if A[i+1]-A[i]<=u{
        //         cn++
        //         i+=2
        //     }else{
        //         i++
        //     }
        // }
        // h:=cn>=p
        if (check(A,u,p)) {
            ans=u
            hi=u-1
        }else{
            lo=u+1
        }
    }
    return ans
}