class Solution {
public:
    using pI=pair<int,int>;
    string reorganizeString(string s) {
        int n=s.size();
        vector<int>freq(26,0);
        for(auto x:s) freq[x-'a']++;

        priority_queue<pI>pq;

        for(int i=0;i<26;i++){
            if(freq[i]>0)
            pq.push({freq[i],i});
        }

        string ans="";
        while(!pq.empty()){
            bool h=false;
            pI x=pq.top();
            pq.pop();

            pI y;
            if(!pq.empty()){
                y=pq.top();
                pq.pop();
                h=1;
            }

            ans+=(x.second+'a');
            --x.first;

            if(x.first>0)
            pq.push({x.first,x.second});

            if(h){
                ans+=(y.second+'a');
                --y.first;
                if(y.first>0)
                pq.push({y.first,y.second});
            }
        }

        for(int i=1;i<n;i++){
            if(ans[i]==ans[i-1]) return "";
        }
        return ans;
    }
};