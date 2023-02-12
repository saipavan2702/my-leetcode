class Solution {
public:
    int minEatingSpeed(vector<int>& p, int h) {
        int k=INT_MAX;
        
        int lo(1),hi(1e9);
        sort(begin(p),end(p));

        auto test=[=](int u){
            long long T=0;
            for(int i:p){
                T+=(ceil(i*1.0/u));
            }
            return T;
        };

        while(lo<=hi){
            int u=(lo+hi)/2;
            if(test(u)<=h){
                k=min(k,u);
                hi=u-1;
            }
            else
            lo=u+1;
        }
        return k;
    }
};