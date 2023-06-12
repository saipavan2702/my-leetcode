class Solution {
public:
    vector<string> summaryRanges(vector<int>& A) {
        int n=A.size();
        vector<string>hash;
        int j=0;

        if(n==0)
        return {};
        if(n==1){
            string s=to_string(A[0]);
            return {s};
        }
        

        for(int i=1;i<n;i++){
            long long int x=1LL*(A[i]);
            long long int y=1LL*(A[i-1]);
            if(x-y!=1){
                if(i-1!=j){
                    string s=to_string(A[j])+"->"+to_string(A[i-1]);
                    hash.push_back(s);
                    j=i;
                }else if(i-1==j){
                    hash.push_back(to_string(A[i-1]));
                    j=i;
                }
                
            }
        }
        long long int x=1LL*(A[n-2]);
        long long int y=1LL*(A[n-1]);
        if(y-x==1){
            string s=to_string(A[j])+"->"+to_string(A[n-1]);
            hash.push_back(s);
        }else{
            string s=to_string(A[n-1]);
            hash.push_back(s);
        }
        return hash;
    }
};