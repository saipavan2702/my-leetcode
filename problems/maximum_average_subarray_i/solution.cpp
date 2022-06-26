class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res=0,n,sum=0;n=nums.size();
        for(int i=0;i<k;i++)
        {
            res+=nums[i];
        }
        sum=res;
        for(int i=k;i<n;i++)
        {
            sum+=nums[i]-nums[i-k];
            if(sum>res)
            {
                res=sum;
            }
        }
        return res/k;
    }
};