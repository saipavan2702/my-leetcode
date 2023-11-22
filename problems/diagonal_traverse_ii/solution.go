type pI struct {
    x int
    y int
}
func findDiagonalOrder(G [][]int) []int {
    n:=len(G)
    queue:=[]pI{};
    queue=append(queue,pI{0,0})
    res:=[]int{}

    for len(queue)>0 {
        p := queue[0]
        x, y := p.x, p.y
        queue=queue[1:];
        res=append(res,G[x][y])
        if y==0 && x+1<n {
            queue=append(queue,pI{x+1,y});
        }
        if (x>=0 && x<n) && (y+1>=0 && y+1<len(G[x])) {
            queue=append(queue,pI{x,y+1});
        }
    }
    return res;

}