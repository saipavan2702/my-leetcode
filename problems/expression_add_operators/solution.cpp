class Solution {
public:
    vector<string>need;
    string s;
    int T;
    vector<string> addOperators(string num, int target) {
        this->s=num;
        this->T=target;
        
        recur(0,"",0,0);
        return need;
    }
    void recur(int x,string u, long have, long ref){
        int n=s.size();
        if(x==n){
            if(have==T){
                need.push_back(u);
                return;
            }
        }
        
        string curr;
        long c=0;
        for(int i=x;i<n;i++){
            if(i>x && s[x]=='0')
            break;
            
            curr+=s[i];
            c=c*10+s[i]-'0';
            if(x==0)
            recur(i+1,u+curr,c,c);
            else{
                recur(i+1,u+"+"+curr,have+c,c);
                recur(i+1,u+"-"+curr,have-c,-c);
                recur(i+1,u+"*"+curr,have-ref+ref*c,ref*c);
            }
        }
    }
};