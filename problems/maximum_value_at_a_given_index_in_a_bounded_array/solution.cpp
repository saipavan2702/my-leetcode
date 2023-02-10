class Solution {
public:
    int maxValue(int n, int idx, int S) {
        S-=n;
        int left(0),right(S);

        auto test=[&](int p){
            int h=max(p-idx,0);
            long a=long(h+p)*(p-h+1)/2;

            h=max(p-((n-1)-idx),0);
            a+=long(h+p)*(p-h+1)/2;

            return a-p;
        };

        while(left<right) {
            
            int u=(left+right+1)/2;

            if(test(u)<=S)
            left=u;
            else
            right=u-1;
        }
        return left+1;
    }
};