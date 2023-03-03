class Solution {
public:
    int strStr(string hay, string need) {
        int j=0;;
        int p=need.size();

        while(j<hay.size()){
            if(hay[j]==need[0]){
                if(hay.substr(j,p)==need)
                return j;
            }
            j++;
        }
        return -1;
    }
};