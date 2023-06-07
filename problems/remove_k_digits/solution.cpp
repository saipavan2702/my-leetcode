class Solution {
public:
    string removeKdigits(string s, int k) {
        int n=s.size();
        string have="";

        for(int i=0;i<n;i++){
            if(have.empty())
            have+=(s[i]);
            else if(have.back()>s[i] && k>0){
                while(!have.empty() && have.back()>s[i] && k-->0){
                    have.pop_back();
                }
                have+=(s[i]);
            }else
            have+=(s[i]);

            if(have.size()==1 && s[i]=='0')
            have.pop_back();
        }

        while(k-->0 && !have.empty()){
            have.pop_back();
        }

        return have==""?"0":have;
    
    }
};