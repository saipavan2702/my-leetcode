func search(A []int, t int) bool {
    lo,hi:=0,len(A)-1

    for lo<=hi {
        u:=(lo+hi)/2
        if A[u]==t {
            return true
        }

        if A[lo]==A[u] && A[hi]==A[u]{
            lo++
            hi--
            continue
        }
        if A[lo]<=A[u] {
            if A[lo]<=t && t<A[u] {
                hi=u-1
            }else{
                lo=u+1
            }
        }else {
            if A[u]<t && t<=A[hi] {
                lo=u+1
            }else{
                hi=u-1
            }
        }
    }
    return false
}
