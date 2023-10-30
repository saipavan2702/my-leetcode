class Solution {
public:
    vector<int> sortByBits(vector<int>& A) {
        unordered_map<int,int>freq;
        for(auto x:A){
            bitset<32>bi(x);
            freq[x]=bi.count();
        }
        sort(A.begin(),A.end(),[&](int a, int b){
            if(freq[a]==freq[b]) return a<b;
            return freq[a]<freq[b];
        });
        return A;
    }
};