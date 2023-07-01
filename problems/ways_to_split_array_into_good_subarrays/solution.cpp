class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& A) {
        int cn= count(A.begin(),A.end(),1);
        int n=A.size();

        if(cn==0)
        return 0;

        if(cn==1)
        return 1;

        vector<int>dist;
        for(int i=0;i<n;i++){
            if(A[i]==1){
                int j=i+1;
                while(j<n and A[j]!=1)
                j++;

                j--;
                dist.push_back(j-i);
                i=j;
            }
        }
        dist.pop_back();

        long long ans=1;
        int MOD=1e9+7;
        for(int i=0;i<dist.size();i++)
        ans=(ans*(dist[i]+1))%MOD;

        return ans%MOD;

    }
};