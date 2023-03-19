class Solution {
public:
     
//     bool recur(int x, int y, vector<vector<int>>&grid,int prev,vector<vector<int>>&vis){
//         int n=size(grid);
        
//         if(x>=n || y>=n || x<0 || y<0)
//             return 0;
       
       
        
       
//         bool a=recur(x-2,y+1,grid,grid[x][y],vis);
//         bool b=recur(x-2,y-1,grid,grid[x][y],vis);
//         bool c=recur(x+2,y-1,grid,grid[x][y],vis);
//         bool d=recur(x+2,y+1,grid,grid[x][y],vis);
//         bool e=recur(x-1,y-2,grid,grid[x][y],vis);
//         bool f=recur(x-1,y+2,grid,grid[x][y],vis);
//         bool g=recur(x+1,y+2,grid,grid[x][y],vis);
//         bool h=recur(x+1,y-2,grid,grid[x][y],vis);
        
//         if(prev+1==grid[x][y])
            
        
//     }
    
    
    using pI=pair<int,int>;
    int dx[8]={1,1,-1,-1,2,2,-2,-2};
    int dy[8]={2,-2,2,-2,1,-1,1,-1};
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n=size(grid);
        queue<pI>q;
        q.push({0,0});
        
        int f=0;
    
        while(!q.empty()){
            int h=0;
            int x=q.front().first;
            int y=q.front().second;
            
            
            q.pop();
            for(int i=0;i<8;i++){
                int r=x+dx[i];
                int c=y+dy[i];
                if(r<n && c<n && r>=0 && c>=0 && grid[r][c]==f+1){
                    x=r;y=c;
                    h=1;
                    break;
                }
            }
            if(h)
            q.push({x,y});
            
            f++;
        }
        return f==n*n;
        
    }
};