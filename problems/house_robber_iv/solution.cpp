class Solution {
public:
    int minCapability(vector<int>& A, int k) {
        int lo(1),hi(1e9+9);

        auto test=[=](int u) {
            int c=0;
            for(int i=0;i<A.size();i++) {

                if(A[i]<=u)
                c++,i++;
            }
            return c;
        };

        while(lo<=hi) {
            int u=(hi+lo)/2;
            cout<<lo<<" "<<u<<" "<<hi<<endl;
            if(test(u)>=k)
            hi=u-1;
            else
            lo=u+1;
        }
        return lo;
    }
};