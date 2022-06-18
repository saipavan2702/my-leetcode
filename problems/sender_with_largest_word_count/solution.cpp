class Solution {
public:
    int rword(string s)
    {
        stringstream str(s);
        string cword;
        int count=0;
        while(str>>cword)
        {
            count++;
        }
        return count;
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string,int>freq;
        for(int i=0;i<senders.size();i++)
        {
            int k=rword(messages[i]);
            freq[senders[i]]+=k;
        }
        string res="";
        int l=0;
        for(auto x:freq)
        {
            if(x.second>l)
            {
               l=max(l,x.second);
               res=x.first;
            } 
            else if(l==x.second)
            {
                res=max(res,x.first);
            }
        }
        return res;
        
    }
};