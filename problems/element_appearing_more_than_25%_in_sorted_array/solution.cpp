class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size(),k;
        if(n&1) k=ceil(n*1.0/4);
        else k=n/4;

        unordered_map<int,int>freq;
        for(int i:arr) freq[i]++;
        for(auto x:freq) if(x.second>=k) return x.first;

        return arr[0];
    }
};