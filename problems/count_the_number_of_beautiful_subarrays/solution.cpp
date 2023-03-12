class Solution {
public:
    long long beautifulSubarrays(vector<int>& A) {
        int n=size(A);
        int r=1;
        
        //(x|r)^x-rth bit is 0
        //r<<=1
        
        unordered_map<int,int>dict;
        dict[0]=1;
        int curr=0;
        long long u=0;
        
        for(int i=0;i<n;i++){
            curr^=A[i];
            if(dict.count(curr))
                u+=dict[curr];
            dict[curr]++;
        }
        return u;
    }
};