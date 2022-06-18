class Solution {
public:
    int jump(vector<int>& nums) {
        int i=0,res=0,ans=0,count=0;
        int n;n=nums.size();
        while(i<n-1)
        {
            res=max(res,i+nums[i]);
            if(i==ans)
            {
                ans=res;
                count++;
            }
            i++;
        }
        return count;
    }
};