class Solution {
public:
    int maximumCandies(vector<int>& c, long long k) {
        int n=c.size();

        long long lo(1),hi(1e9);
        long long need=0;

        auto test=[=](long long u){
            long long can=0;
            for(int i:c){
                can+=(i/u);
            }
            return can;
        };

        while(lo<=hi){
            long long u=(lo+hi)/2;
            if(test(u)<k){
                hi=u-1;
            }
            else
            need=u,lo=u+1;
            
        }
        return need;
    }
};