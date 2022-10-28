class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>dict;
        for(auto&x:strs)
        {
            string r=x;
            sort(r.begin(),r.end());
            dict[r].push_back(x);
        }
        vector<vector<string>>ans;
        for(auto x:dict)
        ans.push_back(x.second);
        
        return ans;
    }
};