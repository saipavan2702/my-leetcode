class Solution {
public:
    vector<string>ans;
    char in[3]={'a','b','c'};
    void track(int n,int k,string&res)
    {
        if(ans.size()==k)
        return;
        if(res.size()==n)
        {
            ans.push_back(res);
            return;
        }
        for(int i=0;i<3;i++)
        {
            if(res.size()==0 or res.back()!=in[i])
            {res+=in[i];
            track(n,k,res);
            res.pop_back();}
        }
    }
    string getHappyString(int n, int k) {
        string res="";
        track(n,k,res);
        return ans.size()==k?ans.back():"";
    }
};