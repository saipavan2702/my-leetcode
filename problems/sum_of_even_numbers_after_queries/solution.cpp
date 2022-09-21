class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n,p;
        n=nums.size();
        p=queries.size();
        
        int s=0;
        for(int i:nums)
        {
            if(!(i&1))
            s+=i;
        }
        
        vector<int>res;
        
        for(int i=0;i<p;i++)
        {
            int x=queries[i][0];
            int y=queries[i][1];
            
            if(nums[y]%2==0)
            s-=nums[y];
            
            nums[y]+=x;
            
            if(nums[y]%2==0)
            s+=nums[y];
            
            res.push_back(s);
        }
        return res;
    }
};