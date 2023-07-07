class Solution {
public:
    int maxConsecutiveAnswers(string Key, int k) {
        unordered_map<char,int>dict;
        int i=0,j=0;
        int n=Key.size();

        int len=0;
        for(int i=0;i<n;i++){
            dict[Key[i]]++;
            while(dict['F']>k and j<=i){
                if(Key[j]=='F')
                dict[Key[j]]--;

                j++;
            }
            len=max(len,i-j+1);
        }
        j=0;
        dict.clear();
        for(int i=0;i<n;i++){
            dict[Key[i]]++;
            while(dict['T']>k and j<=i){
                if(Key[j]=='T')
                dict[Key[j]]--;

                j++;
            }
            len=max(len,i-j+1);
        }
        return len;
    }
};