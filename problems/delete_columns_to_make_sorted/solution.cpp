class Solution {
public:
    int minDeletionSize(vector<string>& str) {
        int cnt=0;

        int n,p;
        n=str.size();
        p=str[0].size();
     
        for(int j=0;j<p;j++) {
            for(int i=0;i<n-1;i++) {
               if(str[i][j]>str[i+1][j]){
                   cnt++;
                   break;
               }
            }
        }

        return cnt;
    }
};