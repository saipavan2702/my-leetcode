class Solution {
public:
    bool canJump(vector<int>& nums) {
        int res=0;
        int n,i,count=0;
        n=nums.size();i=0;
        while(i<=res)
        {
            res=max(i+nums[i],res);
            if(res>=n-1)
            return 1;
            
             i++;
        }
        cout<<count<<endl;
        return 0;
    }
};