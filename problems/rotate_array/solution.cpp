class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int i=0;
        int l;
        int n;
        n=nums.size();
        l=n-(k%n);
        vector<int>temp;
        while(i<n)
        {   
            temp.push_back(nums[l%n]);
            i++;
            l++;
        }
        for(i=0;i<n;i++)
        {
            nums[i]=temp[i];
        }
        
    }
};