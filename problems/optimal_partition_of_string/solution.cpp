class Solution {
public:
    int partitionString(string S) {
        int n=size(S);

        unordered_map<char,int>dict;
        int cnt=0,i=0;
        for(i=0;i<n;i++){
            if(dict.count(S[i])){
                cnt++;
                i--;
                dict.clear();
            }else{
                dict[S[i]]++;
            }
        }
        if(dict.count(S[i])){
            cnt++;
            i--;
            dict.clear();
        }

        return cnt+1;
        
    }
};