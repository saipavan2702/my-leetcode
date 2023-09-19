func findDuplicate(A []int) int {
    vis:=make(map[int]bool)
    for _,x:=range A {
        if(vis[x]){
            return x
        }
        vis[x]=true
    }
    return 69
}