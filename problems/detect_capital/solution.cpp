class Solution {
public:
    bool detectCapitalUse(string s) {
        bool f=0,fl=0,fu=0;
        if(isupper(s[0]))
        f=1;

        for(int i=1;i<s.size();i++) {
            if(isupper(s[i]))
            fu=1;

            if(islower(s[i]))
            fl=1;
        }
        if(f==1){
            return !(fl&fu);
        }
        else
        return fu==0;

    }
};