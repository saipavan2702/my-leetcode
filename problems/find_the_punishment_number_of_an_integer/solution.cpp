class Solution {
public:
    
    bool recur(int x, int need, string s){
        int l=s.size();
            
        if(x==l && need==0)
        return 1;

        if(need<0 || x==l)
            return 0;

        for(int i=x+1;i<=l;i++){
            int have=stoi(s.substr(x,i-x));
            if(recur(i,need-have,s)){
                return 1;
            }
        }
        return 0;
    }
    
    bool check(int i){
        int u=i*i;
        string s=to_string(u);
        return recur(0,i,s);
    }
    
    int punishmentNumber(int n) {
        long long cnt=0;
        
        for(int i=1;i<=n;i++){
            if(check(i)){
                cnt+=(i*i);
            }
        }
        return cnt;
    }
};