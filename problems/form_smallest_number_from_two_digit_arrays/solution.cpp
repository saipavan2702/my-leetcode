class Solution {
public:
    int minNumber(vector<int>& left, vector<int>& right) {
        sort(begin(left),end(left));
        sort(begin(right),end(right));
        vector<int>v(10);
        
        auto it=set_intersection(left.begin(),left.end(),right.begin(),right.end(),v.begin());
        int con=1e9;
        if(it!=v.begin())
            con=v[0];
        
        int s=left[0];
        int l=right[0];
        int ans=min(10*s+l,10*l+s);
        return min(ans,con);
    }
};