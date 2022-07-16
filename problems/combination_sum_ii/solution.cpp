class Solution {
public:
    vector<vector<int>>ans;
    void track(int index, int t, vector<int>&candidates,vector<int>&dp){
        
        if(t== 0){
            ans.push_back(dp);
            return;
        }
        for(int i = index; i< candidates.size(); i++){
            if(candidates[i] > t)
                break; 
            if(i  > index && candidates[i] == candidates[i-1])
                continue;
                
            dp.push_back(candidates[i]);
            track(i+1, t- candidates[i], candidates,dp); 
            dp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int t) {
        sort(candidates.begin(), candidates.end()); 
        
        vector<int>dp;
        track(0, t, candidates,dp);
        return ans;
    }
    
};