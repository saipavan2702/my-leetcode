class Solution {
public:
    bool check(char ch){
        return ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u';
    }
    int vowelStrings(vector<string>& A, int l, int r) {
        int n=size(A);
        
        int cnt=0;
        for(int i=l;i<=r;i++){
            string s=A[i];
            bool x=check(s[0]);
            bool y=check(s[s.size()-1]);
            if(y&&x)
                cnt++;
        }
        return cnt;
    }
};