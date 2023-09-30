func find132pattern(A []int) bool {
    var stack []int
    second:=math.MinInt32
    for i:=len(A)-1;i>=0;i-- {
        if A[i]<second {
            return true
        }else{
            for len(stack)>0 && stack[len(stack)-1]<A[i] {
                second=stack[len(stack)-1]
                stack=stack[:len(stack)-1]
            }
        }
        stack=append(stack,A[i])
    }
    return false
}