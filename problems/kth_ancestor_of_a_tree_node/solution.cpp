class TreeAncestor {
public:
    vector<vector<int>>dp;
    TreeAncestor(int n, vector<int>& parent) {
        dp.resize(n,vector<int>(16,0));

        for(int i=0;i<n;i++){
            dp[i][0]=parent[i];
        }

        for(int j=1;j<16;j++){
            for(int i=0;i<n;i++){
                dp[i][j]=dp[i][j-1]==-1?-1:dp[dp[i][j-1]][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        // recur(k,node,need);
        // return need;

        for(int i=0;i<16;i++){
            if((k>>i)&1){
                node=dp[node][i];

                if(node==-1)
                return -1;
            }
        }
        return node;
    }
    // void recur(int k, int x, int& need){
    //     if(k==0 or x==-1){
    //         need=x;
    //         return;
    //     }
        
    //     recur(k-1,P[x],need);
    //     return;
    // }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */