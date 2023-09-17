class Solution {
public:
    int countWays(vector<int>& A) {
        int n=A.size();
        sort(A.begin(),A.end());
        
        int cnt=0;
        if(A[0]!=0) cnt++;
        
        map<int,int>dict;
        for(int i:A) dict[i]++;
        
        int sz=0;
        for(int i=0;i<n;i++){
            sz+=dict[i];
            if(dict[i]>0){
                if(sz>=n or sz>i and A[sz]>sz) cnt++;
            }
        }
        return cnt;
    }
};