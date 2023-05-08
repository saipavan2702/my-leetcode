class Solution {
public:
    int firstCompleteIndex(vector<int>& A, vector<vector<int>>& G) {
        int n=G.size();
        int p=G[0].size();
        
        unordered_map<int,int>dr,dc,Fr,Fc;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<p;j++){
                dr[G[i][j]]=i;
                dc[G[i][j]]=j;
            }
        }
        
        for(int i=0;i<A.size();i++){
            Fr[dr[A[i]]]++;
            Fc[dc[A[i]]]++;
            
            if(Fr[dr[A[i]]]==p || Fc[dc[A[i]]]==n)
                return i;
        }
        return -1;
    }
};