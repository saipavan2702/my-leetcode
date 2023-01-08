class Solution {
public:
    int maxPoints(vector<vector<int>>& T) {
        int n=T.size();
        int req=0;
        if(n<=2)
        return n;

        for(auto e:T) {
         unordered_map<double,int>freq;
            double x1=e[0];
            double y1=e[1];
            for(auto l:T) {
                double x2=l[0];
                double y2=l[1];
                if(e==l)
                continue;
                
                double slope;
                if(x2==x1){
                    slope=INT_MAX;
                }
                else
                slope=(double)(y2-y1)/(double)(x2-x1);

                freq[slope]++;
                req=max(req,freq[slope]);
            }
        }
        return req+1;
    }
};