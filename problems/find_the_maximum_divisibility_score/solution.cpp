class Solution {
public:
    int maxDivScore(vector<int>& A, vector<int>& D) {
        int n=D.size();
        sort(D.begin(),D.end());
        
        int loc=0,ans=0;
        for(int i:D){
            int cnt=0;
            for(int x:A){
                if(x%i==0)
                    cnt++;
            }
            if(cnt>loc)
                loc=cnt,ans=i;
        }
        if(loc==0)
            ans=D[0];
        
        return ans;
    }
};