class Solution {
public:
    int shipWithinDays(vector<int>& Q, int Y) {
        int n=Q.size();
        int s=*max_element(begin(Q),end(Q));
        int c=accumulate(begin(Q),end(Q),0);
        
        int lo(s),hi(c);

        int ans=1e5;

        auto test=[=](int u) {
            int S=0,d=0;
            for(int i:Q){
              S+=i;
              if(S>u){
                d++;
                S=i;
              }
            }
            d++;
            return d<=Y;
        };

        while(lo<=hi) {
            
            int u=(lo+hi)/2;
            if(test(u)) {
              ans=u;
              hi=u-1;
            }
            else
            lo=u+1;
        }
        return lo;
    }
};