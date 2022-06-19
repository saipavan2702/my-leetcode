class Solution {
public:
    string greatestLetter(string s) {
        map<char,int>freq;
        string ans="";
        for(auto i:s)
        {
           freq[i]++;
            
        }
        sort(s.begin(),s.end());
        for(int i=0;i<s.size();i++)
        {
            if(freq[toupper(s[i])] and freq[tolower(s[i])])
            {
                ans=toupper(s[i]);
            }
                
        }
        return ans;
    }
};