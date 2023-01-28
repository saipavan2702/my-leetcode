class DSU:

    def __init__(self):
        self.P={}
        self.ans= {}

    def do_set(self,x):
        self.P[x]=x
        self.ans[x]=[x,x]
        
    def exists(self,x): 
        return x in self.P
    
    def find(self,r):
        if not self.exists(r):
            return None
        if self.P[r]==r:
            return r
        self.P[r]=self.find(self.P[r])
        return self.P[r]

    def uni(self,u,v):
        a=self.find(u)
        b=self.find(v)

        if a is None or b is None:
            return
        self.P[a]=b

        x=self.ans[a]
        del self.ans[a]

        self.ans[b]=[min(self.ans[b][0],x[0]),max(self.ans[b][1],x[1])]



class SummaryRanges:

    def __init__(self):
        self.dsu=DSU()

    def addNum(self, val: int) -> None:
        if self.dsu.exists(val):
            return
        
        self.dsu.do_set(val)
        self.dsu.uni(val,val-1)
        self.dsu.uni(val,val+1)

    def getIntervals(self) -> List[List[int]]:
        return sorted(self.dsu.ans.values())


# Your SummaryRanges object will be instantiated and called as such:
# obj = SummaryRanges()
# obj.addNum(value)
# param_2 = obj.getIntervals()