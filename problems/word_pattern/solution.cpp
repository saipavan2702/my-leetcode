class Solution {
public:
    bool wordPattern(string P, string s) {
        int n=P.size();

        stringstream ss(s);
        int i=0,cnt=0;
        bool fl=1;
        string str;
        unordered_map<string,char>dict;
        unordered_map<char,string>freq;

        while(ss>>str or i<n) {
            if(dict.count(str) || freq.count(P[i])) {
                if(dict[str]!=P[i] or freq[P[i]]!=str)
                fl=0;
            }
            else
            dict[str]=P[i],freq[P[i]]=str;

            i++;
            cnt++;
        }
        return (fl && i==cnt);
    }
};