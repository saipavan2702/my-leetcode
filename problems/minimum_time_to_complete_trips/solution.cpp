class Solution {
public:
    long long minimumTime(vector<int>&t, int T) {
        using ll=long long int;
        
        ll ans=0;
        int n=size(t);

        ll lo(1), hi(1e14);

        auto test=[&](ll u){
            ll cnt=0;
            for(auto x:t){
                if(x<=u) {
                    cnt+=u/x;
                }
            }
            return cnt;
        };

        while(lo<hi){
            ll u=(lo+hi)/2;
            if(test(u)>=T)
            hi=u;
            else
            lo=u+1;
        }
        return hi;
    }
};