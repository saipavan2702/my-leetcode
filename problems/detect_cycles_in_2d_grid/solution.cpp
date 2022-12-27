class Solution {
public:
    int find(int r,int P[]) {
        if(P[r]==r)
        return r;

        return find(P[r],P);
    }
    void uni(int u,int v, int P[]) {
        int a=find(u,P);
        int b=find(v,P);

        if(a!=b)
        P[b]=a;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n,p;
        n=grid.size();
        p=grid[0].size();
        
        int P[n*p];
        for(int i=0;i<n*p;i++)
        P[i]=i;
        
        int dir[3]={0,-1,0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<p;j++)
            {
                int a=find(i*p+j,P);
                for(int r=0;r<2;r++)
                {
                    int x=i+dir[r];
                    int y=j+dir[r+1];

                    if(x<0 or y<0 or grid[i][j]!=grid[x][y])
                    continue;

                    int b=find(x*p+y,P);
                    if(a==b)
                    return 1;

                    uni(a,b,P);
                }
            }
        }
        return 0;
    }
};