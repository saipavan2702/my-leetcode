class Solution {
public:
    string mergeAlternately(string A, string B) {
        int n=A.size(),p=B.size();

        int i=0,j=0;
        string s="";
        while(i<n || j<p){
            if(i<n)
            s+=A[i++];

            if(j<p)
            s+=B[j++];
        }
        return s;
    }
};