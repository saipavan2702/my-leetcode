class Solution:
    def countPaths(self, grid: List[List[int]]) -> int:
        dz,mod=[(1,0),(0,-1),(-1,0),(0,1)],10**9+7
        n,p=len(grid),len(grid[0])

        @cache
        def recur(i,j):
            return sum((1+recur(i+x,j+y)) for x,y in dz if 0<=i+x<n and 0<=j+y<p and grid[i+x][j+y]>grid[i][j])%mod
        cn=0
        for i in range(n):
            for j in range(p):
                cn=(cn+recur(i,j))%mod
        return cn+(n*p)%mod