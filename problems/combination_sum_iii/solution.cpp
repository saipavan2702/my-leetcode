class Solution {
public:
    vector<vector<int>>ans;
    void track(int k,int n,int arr[],vector<int>&res,int x)
    {
        if(n==0 and k==0)
        {
         ans.push_back(res);
         return;
        }
        for(int i=x;i<9;i++)
        {
            if(n<arr[i])
            continue;
            
            res.push_back(arr[i]);
            track(k-1,n-arr[i],arr,res,i+1);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int arr[9]={1,2,3,4,5,6,7,8,9};
        vector<int>res;
        track(k,n,arr,res,0);
        return ans;
    }
};