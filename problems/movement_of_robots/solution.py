class Solution:
    def sumDistance(self, R: List[int], s: str, d: int) -> int:
        
        for i,e in enumerate(s):
            if e=='L':
                R[i]-=d
            elif e=='R':
                R[i]+=d
        
        
        R.sort()
        total=0
        curr=0
        
        for i,e in enumerate(R):
            total+=e*i-curr
            curr+=e
        
        return total%(10**9+7)
        