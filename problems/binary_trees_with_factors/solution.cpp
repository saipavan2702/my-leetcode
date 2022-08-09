#define ll long long int 
#define mod 1000000007
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n;
        ll res=0;
        n=arr.size();
        sort(arr.begin(),arr.end());
        
        unordered_map<int,ll>freq;
        for(int i=0;i<n;i++)
        {
            freq[arr[i]]=1;
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0 and freq[arr[i]] and freq[arr[i]/arr[j]])
                freq[arr[i]]=(freq[arr[i]]+freq[arr[j]]*freq[arr[i]/arr[j]])%mod;
            }
             res=(res+freq[arr[i]])%mod;
        }
        return res;
    }
};