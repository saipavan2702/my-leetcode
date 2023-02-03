class Solution {
public:
    string convert(string s, int R) {
        int n=s.size();
        if(R==1)return s;

        vector<string>Q(R,"");
        int j=0;
        bool f=1;

        for(int i=0;i<n;i++) {
            if(j==0 or j==R-1)
            f=!f;

            Q[j]+=s[i];
            f==true?j--:j++;
        }
        string p="";
        for(auto &x:Q){
            p+=x;
        }
        return p;
    }
};