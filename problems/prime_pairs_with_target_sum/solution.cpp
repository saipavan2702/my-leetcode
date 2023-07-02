class Solution {
public:
   
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>>ans;
        int N=1e6+1;
        
        vector<bool>P(N,1);
        P[0]=0;
        P[1]=0;
        
        for (int i=2;i*i<=N;i++) {
            if(P[i]){
                for(int j=i*i;j<=N;j+=i){
                    P[j]=0;
                }
            }
        }
        
        
        for(int i=2;i<=n/2;i++){
            if(P[i] && P[n-i])
                ans.push_back(vector<int>{i,n-i});
        }
        return ans;
    }
    
};