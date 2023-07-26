class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        int lo(1),hi(1e7);
        int ans=-1;

        auto test=[&](int u){
            double cn=0;
            for(int i=0;i<n-1;i++){
                cn+=ceil((dist[i]*1.0/u));
            }
            cn+=(dist[n-1]*1.0/u);
            return cn<=hour;
        };

        while(lo<=hi){
            int u=(lo+hi)/2;
            if(test(u)) ans=u,hi=u-1;
            else lo=u+1;
        }
        return ans;
    }
};