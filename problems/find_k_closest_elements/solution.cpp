class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n;
        n=arr.size();
        
        int l=0,r=n-1;
        while(r-l>=k)
        {
            if((arr[r]-x)>=(x-arr[l]))
            r--;
            else
            l++;
            
            cout<<r;
        }
        return vector<int>(begin(arr)+l,begin(arr)+r+1);
    }
};