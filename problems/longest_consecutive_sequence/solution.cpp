class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         if(nums.size()==0)
        return 0;
        
        unordered_set<int>st;
        for(auto x:nums)
        {
            st.insert(x);
        }
        nums.clear();
        for(int x:st)
        {
            nums.push_back(x);
        }
        int n,res=INT_MIN,len=1;
        n=nums.size();
        if(n==1)
        return 1;
        int x=0,y=1;
        sort(nums.begin(),nums.end());
        while(y<n)
        {
            if(nums[y]-nums[x]!=len)
            {
                res=max(res,len);
                x=y;
                len=1;
            }
            else if(nums[y]-nums[x]==len)
            len++;
            
            y++;
        }
        if(nums[n-1]-nums[n-2]==1)
        res=max(res,len);
        
        return res;
    }
};