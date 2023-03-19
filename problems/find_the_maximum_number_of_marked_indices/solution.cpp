class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>&A) {
        int n=size(A);
        sort(begin(A),end(A));

        int cnt=0;
        int j=n/2;
        for(int i=0;i<n/2 && j<n;){
            if(2*A[i]<=A[j])
            cnt+=2,i++;

            j++;
        }
        return cnt;
        
    }
};