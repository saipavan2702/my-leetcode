class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n;
        n=nums.size();
        
        int l=0,ret=0;
        while(l<=ret){
           ret=max(ret,l+nums[l]);
           if(ret>=n-1)
           return 1;

           l++;
        }
        return 0;
    }
};