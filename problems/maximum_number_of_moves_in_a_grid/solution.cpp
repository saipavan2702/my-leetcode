class Solution {
public:
    
    int recur(int x, int y, vector<vector<int>>& G, vector<vector<int>>& dp){
        int n=G.size();
        int p=G[0].size();
        
        if(x<0 || x>=n || y<0 || y>=p)
            return 0;
            
        if(dp[x][y]!=-1)
            return dp[x][y];
        
        int a=0,b=0,c=0;
        
        if(x-1>=0 && y+1<p && G[x][y]<G[x-1][y+1]){
            a=1+recur(x-1,y+1,G,dp);
        }
        
        
        
        if(x>=0 && y+1<p && x<n && G[x][y]<G[x][y+1]){
            b=1+recur(x,y+1,G,dp);
        }
        
        
        
        if(x+1<n && y+1<p && G[x][y]<G[x+1][y+1]){
            c=1+recur(x+1,y+1,G,dp);
        }
        
        return dp[x][y]=max({a,b,c});
    }
    
    int maxMoves(vector<vector<int>>& G) {
        int n=G.size();
        int p=G[0].size();
        
        vector<vector<int>>dp(n+1,vector<int>(p+1,-1));
        
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,recur(i,0,G,dp));
        }
        return ans;
    }
};