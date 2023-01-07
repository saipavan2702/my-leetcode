class Solution {
public:
    int canCompleteCircuit(vector<int>& T, vector<int>& C) {
        int n=T.size();
        int curr(0),ret(0),idx(0);

        for(int i=0;i<n;i++){
            ret+=T[i]-C[i];
            if(curr<0){
               curr=0;
               idx=i;
            }
            curr+=T[i]-C[i];
        }
        return (ret<0)?-1:idx;
        
    }
};