class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n;n=nums.size();
        vector<int>res(n,-1);
        if(n<2*k+1)
        return res;
        long long int sum=0,i,j=0;
        for(i=0;i<(2*k+1);i++)
        {
            sum+=nums[i];
        }
        i--;
        res[i-k]=sum/(2*k+1);
        for(int r=k+1;i<n-1;r++,j++)
        {
            sum+=nums[++i]-nums[j];
            res[r]=sum/(2*k+1);
        }
        return res;
    }
};