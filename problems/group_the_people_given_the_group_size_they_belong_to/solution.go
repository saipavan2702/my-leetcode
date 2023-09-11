func groupThePeople(A []int) [][]int {
    grp := make(map[int][]int)
    var res [][]int
    
    for i, size := range A {
        grp[size] = append(grp[size], i)
        
        if len(grp[size]) == size {
            res = append(res, grp[size])
            grp[size] = []int{}
        }
    }
    return res
}