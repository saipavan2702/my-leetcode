class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>freq;
        freq[0]=1;
        int curr=0,req=0;
        for(int i:nums){
            curr=(curr+k+i)%k;
            req+=freq[(k+curr)%k];
            freq[(k+curr)%k]++;
        }
        return req;
    }
};