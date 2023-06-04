class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& Q) {
        long long ans=0;
        vector<bool>row(n,false),col(n,false);
        int rCnt=n,cCnt=n;
        
        for(int i=Q.size()-1;i>=0;i--){
            if(!Q[i][0]){
                if(!row[Q[i][1]]){
                    row[Q[i][1]]=true;
                    ans+=(rCnt*Q[i][2]);
                    cCnt--;
                }
            }else{
                if(!col[Q[i][1]]){
                    col[Q[i][1]]=true;
                    ans+=(cCnt*Q[i][2]);
                    rCnt--;
                }
            }
        }
        return ans;
        
    }
};