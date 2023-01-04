class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>freq;
        for(auto t:tasks) {
            freq[t]++;
        }
        
        int cnt=0;
        for(auto [x,y]:freq) {
            if(y==1)
            return -1;

            int l3=y/3;
            if(y%3==0) {
            cnt+=l3;
            }
            else
            cnt+=l3+1;
        }
        return cnt;
    }
};