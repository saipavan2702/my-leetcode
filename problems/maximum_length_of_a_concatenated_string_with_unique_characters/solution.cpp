class Solution {
public:
    int recur(vector<bitset<26>>&ret,bitset<26>s,int idx)
    {
        int cnt=s.count();
        for(int i=idx;i<ret.size();i++)
        {
            if(!((ret[i]&s).any()))
            cnt=max(cnt,recur(ret,s|ret[i],i+1));
        }
        return cnt;
    }
    int maxLength(vector<string>& arr) {
        int n;
        n=arr.size();
        
        vector<bitset<26>>ret;
        for(int i=0;i<n;i++)
        {
            bitset<26>s;
            for(auto&x:arr[i])
            s.set(x-'a');
            
            if(s.count()==arr[i].size())
            ret.push_back(s);
        }
        
        int ans=recur(ret,bitset<26>(),0);
        return ans;
    }
};