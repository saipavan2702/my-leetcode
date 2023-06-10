class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<pair<int,int>>st;
        sort(nums.begin(),nums.end());
        

        auto bs=[&](int lo, int x){
            int hi=nums.size()-1;
            while(lo<=hi){
                int u=(lo+hi)/2;
                if(nums[u]==x)
                return u;
                else if(nums[u]<x)
                lo=u+1;
                else
                hi=u-1;
            }
            return -1;
        };


        for(int i=0;i<nums.size();i++){
            int need=bs(i+1,nums[i]+k);
            if(need!=-1)
            st.insert({nums[i],nums[need]});
        }
        return st.size();
    }
};