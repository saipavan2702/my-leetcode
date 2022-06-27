class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int cnt=0;
        vector<int>res;
        string s="";
        s=to_string(num);
        for(int i=0;i<=s.size()-k;i++)
        {
            string str=s.substr(i,k);
            int r=stoi(str);
            if(r!=0 and num%r==0)
            {
                cnt++;
            }
        } 
        return cnt;
    }
};