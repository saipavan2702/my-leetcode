class Solution {
public:
    int findRadius(vector<int>& hoe, vector<int>& heat) {
        int n=heat.size();
        sort(begin(heat),end(heat));

        int Q(0);
        auto test=[=](int i){
            int lo(0),hi(n-1);
            int lb=-1,ub=-1;

            while(lo<=hi) {
                int u=(lo+hi)/2;
                if(heat[u]>i){
                    ub=heat[u];
                    hi=u-1;
                }
                else{
                    lb=heat[u];
                    lo=u+1;
                }

            }
            return make_pair(lb,ub);
        };

        for(int i:hoe) {
            auto [x,y]=test(i);
            int d=1e9+1;

            if(x!=-1)
            d=min(d,i-x);

            if(y!=-1)
            d=min(d,y-i);

            Q=max(Q,d);
        }
        return Q;
        
    }
};