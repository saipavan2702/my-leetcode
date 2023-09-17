class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int cn=0;
        for(int i=0;i<nums.size();i++){
            bitset<32>bit(i);
            if(bit.count()==k) cn+=nums[i];
        }
        return cn;
    }
};