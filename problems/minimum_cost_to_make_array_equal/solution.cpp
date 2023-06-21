class Solution {
public:
    long long minCost(vector<int>& dat, vector<int>& cost) {
        int n=dat.size();
        long long curr=0,conv=0;
        
        int lo(0),hi(1000000);
        while(lo<=hi){
            int u=(lo+hi)/2;

            curr=conv=0;
            for(int i=0;i<n;i++){
                curr+=1LL*abs(u-dat[i])*cost[i];
                conv+=1LL*abs(u+1-dat[i])*cost[i];
            }

            if(curr<conv)
            hi=u-1;
            else
            lo=u+1;
        }
        return min(curr,conv);
    }
};