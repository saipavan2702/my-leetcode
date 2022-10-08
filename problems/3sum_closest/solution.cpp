class Solution {
public:
    int threeSumClosest(vector<int>& nums, int t) {
        int x,y;
        int cnt=INT_MAX;
        int ans=0;
        sort(nums.begin(),nums.end());
        int n;
        n=nums.size();
        
        for(int i=0;i<n-2;i++)
        {
            x=i+1;
            y=n-1;
            while(y>x)
            {
                int s=nums[i]+nums[x]+nums[y];
                if(s<=t)
                {
                    if(cnt>t-s)
                    {
                        cnt=t-s;
                        ans=s;
                    }
                    x++;
                }
                else
                {
                    if(cnt>s-t)
                    {
                        cnt=s-t;
                        ans=s;
                    }
                    y--;
                }
            }
        }
        return ans;
    }
};