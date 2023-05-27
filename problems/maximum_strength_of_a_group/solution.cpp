class Solution {
public:
    long long maxStrength(vector<int>& A) {
        int n=A.size();
        long long lo=-1e15;
        
        function<long long(int,long long,bool)>recur=[&](int i,long long curr,bool took){
            if(i>=n)
            return took?curr:lo;
        
            long long a=recur(i+1,curr*A[i],true);
            long long b=recur(i+1,curr,took);
            
            return max(a,b);
        };
        return recur(0,1,false);
        
    }
};