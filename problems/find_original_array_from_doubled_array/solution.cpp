class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n;
        n=changed.size();
        
        if(n%2)
        return {};
        
        sort(changed.begin(),changed.end());
        unordered_map<int,int>freq;
        int cnt=n/2;
        
        for(int i:changed)
        freq[i]++;
        
        vector<int>a;
        for(int i:changed)
        {
          if(freq.find(2*i)!=freq.end() and cnt>0 and freq[2*i]!=0 and freq[i]!=0)
          {
              cnt--;
              freq[2*i]--;
              freq[i]--;
              a.push_back(i);
          }
        }
        
        if(cnt!=0)
        return {};
        
        for(auto x:freq)
        if(x.second!=0)
        return {};
        
        return a;
        
        
    }
};