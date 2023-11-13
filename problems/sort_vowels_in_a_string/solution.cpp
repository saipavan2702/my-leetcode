class Solution {
public:
    string sortVowels(string s) {
        vector<int>dict(256,0);
        function<bool(char)>isV=[&](char x)->bool{
            return x=='A' or x=='E' or x=='I' or x=='O' or x=='U' or x=='a' or x=='e' or x=='i' or x=='o' or x=='u';
        };

        for(auto &x:s){
            if(isV(x)) dict[x-'A']++,x='#';
        }

        for(auto &x:s){
            if(x=='#'){
                for(int i=0;i<256;i++) if(dict[i]!=0){
                    x=i+'A';
                    dict[i]--;
                    break;
                } 
            }
        }
        return s;
    }
};