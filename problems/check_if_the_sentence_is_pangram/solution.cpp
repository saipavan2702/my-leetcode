class Solution {
public:
    bool checkIfPangram(string s) {
        int dict[26]={0};
        for(auto&x:s)
         dict[x-'a']++;
        
        for(int i=0;i<26;i++)
        {
            if(dict[i]==0)
            return 0;
        }
        return 1;
    }
};