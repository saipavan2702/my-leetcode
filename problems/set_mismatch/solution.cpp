class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n;
        n=nums.size();
        
        int sum=n*(n+1)/2;
        vector<int>ret(2);
        
        bool vis[10001]={0};
        for(int i=0;i<n;i++)
        {
            sum-=nums[i];
            if(vis[nums[i]])
            ret[0]=nums[i];
            
            vis[nums[i]]=1;
        }
        ret[1]=sum+ret[0];
        return ret;
        
    }
};