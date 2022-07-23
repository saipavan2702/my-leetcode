class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long int cnt=0,k=0;
        int n;n=nums.size();
        //vector<int>res;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                k++;
            }
            else
            {
                //res.push_back(k);
               
                int sus;
                sus=((k*(k+1))/2);
                cnt+=sus;
                k=0;
            }
        }
        cnt+=((k*(k+1))/2);
        return cnt;
    }
};