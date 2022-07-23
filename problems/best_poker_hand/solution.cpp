class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        char ch=suits[0];
        int cnt=0;
        for(auto x:suits)
        {
            if(x==ch)
            cnt++;
        }
        if(cnt==5)
        return "Flush";
        
        unordered_map<int,int>freq;
        for(auto x:ranks)
        {
            freq[x]++;
        }
        for(auto x:freq)
        {
            if(x.second>=3)
            return "Three of a Kind";
        }
        for(auto x:freq)
        {
            if(x.second==2)
            return "Pair";
        }
        return "High Card";
    }
};