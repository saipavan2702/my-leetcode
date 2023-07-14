class Solution {
public:
    int longestSubsequence(vector<int>& arr, int di) {
        int n=arr.size();
        unordered_map<int,int>dict;

        int hi=0;
        for(int &i:arr){
            if(dict.find(i-di)!=dict.end())
            dict[i]=dict[i-di]+1;
            else
            dict[i]=1;

            hi=max(hi,dict[i]);
        }
        return hi;
    }
};