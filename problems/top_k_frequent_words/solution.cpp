class Solution {
public:
    bool static use(pair<int,string>& a , pair<int,string>& b){
        if(a.first==b.first)
        return a.second<b.second;
        
        return a.first>b.first;
    }
    
    vector<string> topKFrequent(vector<string>&w, int k) {
        unordered_map<string , int>freq;
        for(auto&x:w){
            freq[x]++;
        }
       
        vector<pair<int, string>> pq;
        for( auto x:freq){
            pq.push_back({x.second ,x.first});
        }
        sort(pq.begin(),pq.end(),use);
        
        vector<string> ans(k);
        
        for(int i=0;i<k;i++)
        ans[i]= pq[i].second;
        
        return ans;
    }
};