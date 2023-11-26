class Solution:
    def largestSubmatrix(self, G: List[List[int]]) -> int:
        n,p=len(G),len(G[0])

        for i in range(1,n):
            for j in range(p):
                if G[i][j]==1:
                    G[i][j]+=G[i-1][j]
        need=0

        for x in G:
            x.sort(reverse=True)
            for j in range(p):
                need=max(need,x[j]*(j+1))
        return need
        
        