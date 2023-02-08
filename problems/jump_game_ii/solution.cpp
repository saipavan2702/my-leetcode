class Solution {
public:
    int jump(vector<int>& nums) {
        int res=0,curr=0,n=nums.size();
        int i=0;
        int u=0;
        while(i<n-1){
            curr=max(curr,i+nums[i]);
            if(i==res){
                res=curr;
                u++;
            }
            i++;
        }
        return u;
    }
};