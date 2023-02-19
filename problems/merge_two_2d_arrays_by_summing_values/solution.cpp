class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& A, vector<vector<int>>& B) {
//         for(auto x:B){
//             A.push_back(x);
//         }
//         sort(begin(A),end(A));
        
        vector<vector<int>>Q;
        // int n=A.size();
        // int p=B.size();
        
        // for(int i=0;i<n-1;i++){
        //     if(A[i][0]==A[i+1][0]){
        //         A[i][1]+=A[i+1][1];
        //         Q.push_back(A[i]);
        //         // A[i].erase(A[i].begin(),A[i].end());
        //     }
        //     else
        //         Q.push_back(A[i]);
        // }
        
        // int i=0,j=0;
        // while(i<n || j<p){
        //     if(A[i][0]==B[j][0]){
        //         A[i][1]+=B[i][1];
        //         Q.push_back(A[i]);
        //         i++;
        //         j++;
        //     }
        //     else {
        //         if(A[i][0]<B[j][0])
        //         Q.push_back(A[i]),i++;
        //         else 
        //         Q.push_back(B[j]),j++;
        //     }
        // }
        
        
        unordered_map<int,int>freq;
        for(auto x:A){
            freq[x[0]]=x[1];
        }
        for(auto x:B){
            freq[x[0]]+=x[1];
        }
        for(auto [x,y]:freq){
            Q.push_back({x,y});
        }
        sort(begin(Q),end(Q));
        return Q;
        
    }
};