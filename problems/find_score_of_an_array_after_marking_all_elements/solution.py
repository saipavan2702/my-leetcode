class Solution:
    def findScore(self, A: List[int]) -> int:
        pq=[(A,i) for i,A in enumerate(A)]
        heapq.heapify(pq)
        
        vis=set()
        h=0
        while pq:
            x,i=heapq.heappop(pq)
            if i not in vis:
                h+=x
                vis.add(i)
                vis.add(i+1)
                vis.add(i-1)
            
        
        return h