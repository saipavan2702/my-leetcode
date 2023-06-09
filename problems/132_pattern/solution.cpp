class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;

        int se=-1e9;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<se)
            return 1;
            else{
                while(!st.empty() && st.top()<nums[i])
                se=st.top(),st.pop();
            }
            st.push(nums[i]);
        }
        return 0;
    }
};