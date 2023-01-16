class Solution {
public:
    vector<vector<int>>insert(vector<vector<int>>& T,vector<int>& I) {
        vector<vector<int>>ret;
        for(auto&x:T){
            if(x[1]<I[0])
            ret.push_back(x);
            else if(x[0]>I[1])
            ret.push_back(I),I=x;
            else{
                I[0]=min(I[0],x[0]);
                I[1]=max(I[1],x[1]);
            }
        }
        ret.push_back(I);
        return ret;
    }
};