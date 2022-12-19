class Solution {
public:
    string removeDigit(string s, char d) {
        priority_queue<string>pq;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==d)
            {
             string r=s;
             pq.push(r.erase(i,1));
            }
        }
        return (pq.top());
    }
};