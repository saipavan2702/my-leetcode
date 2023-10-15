class Solution {
public:
    vector<int> findIndices(vector<int>& A, int iD, int vD) {
        int n=A.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(abs(i-j)>=iD){
                    if(abs(A[i]-A[j])>=vD) return vector<int>{i,j};
                }
            }
        }
        return vector<int>{-1,-1};
    }
};