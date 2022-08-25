class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    int i,n,res=1;
    int maxx=0;
    set<int>st;
    for(auto i:nums)
    {
        st.insert(i);
    }
    nums.clear();
    for(auto i:st)
    {
      nums.push_back(i);
    }
    n=nums.size();
    if(n==0)
    return 0;
        
    if(n==1)
    return 1;
        
    for(i=0;i<n-1;i++)
    {
        if(nums[i+1]-nums[i]==1)
        {
           res++;
        }
        else
        {
            maxx=max(res,maxx);
            res=1;
        }
        
    }
    if(nums[n-1]-nums[n-2]==1)
    maxx=max(res,maxx);
        
    return maxx;
    }
};