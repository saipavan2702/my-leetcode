class Solution {
public:
    bool check(int i, int j, vector<vector<int>>& Q){
        int n=Q.size();
        if(i>=0 && i<n && j>=0 && j<n && Q[i][j]==0)
        return 1;

        return 0;
    }
    int maxDistance(vector<vector<int>>& Q) {
        int n=Q.size();
        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(Q[i][j]==1)
                q.push({i,j});
            }
        }
        if(q.size()==n*n)
        return -1;

        int h=0;
        while(!q.empty()) {
            int sz=size(q);

            while(sz--) {
                auto [x,y]=q.front();
                q.pop();
                
                const int dp[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
                for(int i=0;i<4;i++) {
                    int dx=dp[i][0];
                    int dy=dp[i][1];

                    if(check(x+dx,y+dy,Q)){
                        Q[x+dx][y+dy]=1;
                        q.push({x+dx,y+dy});
                    }
                }
            }
            h++;
        }
        cout<<h;
        h--;
        return h;
    }
};