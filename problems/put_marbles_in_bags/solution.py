class Solution:
    def putMarbles(self, T: List[int], k: int) -> int:
        n=len(T)
        Q=[0]*(n-1)
        for i in range(0,n-1):
            Q[i]=T[i]+T[i+1]
        Q.sort()
        need=0
        for i in range(0,k-1):
            need-=Q[i]
            need+=Q[n-i-2]
        
        return need
