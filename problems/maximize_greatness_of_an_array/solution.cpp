class Solution {
public:
    int maximizeGreatness(vector<int>&A) {
        int h=0;
        int i(0),j(0);
        
        int n=size(A);
        sort(begin(A),end(A));
        
        for(int i=0;i<n;i++){
            if(A[i]>A[j])
                j++,h++;
        }
        return h;
    }
};