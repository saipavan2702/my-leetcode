class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
         int n;n=nums.size();
    int flag=-1,res=INT_MAX,sus=INT_MIN,tail=-1;
    int r=0;
    while(r<n-1)
    {
        if(nums[r]>nums[r+1])
        {
            if(flag==-1)
            {flag=r;}
            tail=r+1;
            res=min(res,nums[r+1]);
            sus=max(sus,nums[r]);
        }
        r++;
    }
    for(int i=0;i<flag;i++)
    {
       if(nums[i]>res)
      {
        flag=i;
      }
    }
    for(int i=n-1;i>tail;i--)
    {
       if(nums[i]<sus)
       {
         tail=i;
       }
    }
  
    if(flag!=-1)
    return tail-flag+1;
    
    return 0;
    }
};