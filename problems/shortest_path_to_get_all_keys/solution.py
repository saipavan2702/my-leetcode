class Solution:
    def shortestPathAllKeys(self, grid: List[str]) -> int:
        n,p=len(grid),len(grid[0])
        queue,keys=[],0

        for i in range(n):
            for j in range(p):
                if grid[i][j] in "abcdef":
                    keys+=1
                if grid[i][j]=="@":
                    queue.append((i,j,0))
        
        vis={(i,j,0)}
        offset = ((0, 1), (1, 0), (-1, 0), (0, -1))

        cn=0
        while queue:
            sz=len(queue)
            for i in range(sz):
                u,v,h=queue.pop(0)
                if h==((1<<keys)-1):
                    return cn

                for dx,dy in offset:
                    bit=h
                    x=u+dx
                    y=v+dy

                    if x<0 or y<0 or x>=n or y>=p or grid[x][y]=="#":
                        continue
                    if grid[x][y].isupper():
                        if (bit & (1<<(ord(grid[x][y])-ord('A'))))==0:
                            continue
                    if grid[x][y].islower():
                        bit = bit | (1<<(ord(grid[x][y])-ord('a')))
                    
                    if (x,y,bit) not in vis:
                        vis.add((x,y,bit))
                        queue.append((x,y,bit))
            cn+=1

        return -1






        