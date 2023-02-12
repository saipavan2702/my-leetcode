class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        
        long long s=0;
        for(int i=0;i<n/2;i++){
            auto x=to_string(nums[i]);
            auto y=to_string(nums[n-i-1]);
            
            auto z=x+y;
            s+=(stoi(z));
        }
        cout<<s;
        if(n&1){
            s+=nums[n/2];
        }
        return s;
    }
};