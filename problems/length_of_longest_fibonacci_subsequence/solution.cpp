class Solution {
public:
    int lenLongestFibSubseq(vector<int>& nums) {
        int n,l=2,sus=2;n=nums.size();
    set<int>freq(nums.begin(),nums.end());

    for(int i=0;i<n-1;i++)
    {
       for(int j=i+1;j<n;j++)
       {   int a=nums[i];
           int b=nums[j];
           l=2;
           while(freq.find(a+b)!=freq.end())
           {
               b=a+b;
               a=b-a;
               l++;
           }
           sus=max(sus,l);
       }
    }
    if(sus==2)return 0;
    
    return sus;
    }
};