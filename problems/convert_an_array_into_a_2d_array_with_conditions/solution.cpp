class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& A) {
        unordered_map<int,int>freq;
        int have=0;
        
        for(int i:A)
            freq[i]++,have=max(have,freq[i]);
        
        vector<vector<int>>ans;
        for(int i=0;i<have;i++){
            vector<int>v;
            for(auto &x:freq){
                if(x.second)
                v.push_back(x.first),x.second--;
            }
            ans.push_back(v);
        }
        return ans;
        
        
    }
};