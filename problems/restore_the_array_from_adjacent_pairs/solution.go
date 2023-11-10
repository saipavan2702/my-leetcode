func restoreArray(aP [][]int) []int {
    adj:=make(map[int][]int,len(aP));
    for _,x:=range aP {
        adj[x[0]]=append(adj[x[0]],x[1]);
        adj[x[1]]=append(adj[x[1]],x[0]);
    }
    node:=1
    for x,y:=range adj{
        if len(y)==1{
            node=x
        }
    }

    ans:=make([]int,0,len(adj));
    ans=append(ans,node);
    vis:=make(map[int]bool,len(adj));
    vis[node]=true;
    
    var recur func(int);
    recur=func(node int){
        for _,v:=range adj[node]{
            _,have:=vis[v]; if have==false{
                ans=append(ans,v);
                vis[v]=true;
                recur(v);
            }
        }
    }
    recur(node)
    return ans;
}