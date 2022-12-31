class Solution {
public:
    int cnt=0;
    using pI=pair<int,int>;
    void recur(pI curr, pI dest, int ret, vector<vector<int>>& T) {
       int n,p;
        n=T.size();
        p=T[0].size();

       int x=curr.first;
       int y=curr.second;
       
       if(x<0 || x>=n || y<0 || y>=p || T[x][y]==-1)
       return;

       if(curr==dest & ret==-1){
        cnt++;
        return;
       }
    
       T[x][y]=-1;
       recur({x-1,y},dest,ret-1,T);
       recur({x+1,y},dest,ret-1,T);
       recur({x,y-1},dest,ret-1,T);
       recur({x,y+1},dest,ret-1,T);
       T[x][y]=0;
    }
    int uniquePathsIII(vector<vector<int>>& T) {
        int n,p;
        n=T.size();
        p=T[0].size();
        
        pI r,l;
        int ret=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<p;j++) {
                if(T[i][j]==1)
                r={i,j};

                if(T[i][j]==2)
                l={i,j};

                if(T[i][j]==0)
                ret++;
            }
        }
        
        recur(r,l,ret,T);
        return cnt; 

    }
};