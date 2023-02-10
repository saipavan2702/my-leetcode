class Solution {
public:
    int minimizedMaximum(int n, vector<int>& Q) {
        int p=Q.size();
        int left(1),right(1e5);

        auto test=[=](int h){
            int s=0;
            for(int i:Q){
                s+=ceil(i*1.0/h);
            }
            return s;
        };

        while(left<=right){
            int u=(left+right)/2;
            
            if(test(u)<=n)
            right=u-1;
            else
            left=u+1;
        }
        return left;
    }
};