class Solution {
public:
    string smallestString(string s) {
        int n=s.size();
        int idx=-1;
        
       int cnt=count(s.begin(),s.end(),'a');
        if(cnt==n){
            s[n-1]='z';
            return s;
        }
        
        bool h=0;
        int fidx=-1;
        
        for(int i=0;i<n;i++){
            if(s[i]!='a'){
                fidx=i;
                break;
            }
        }
        
        for(int i=0;i<n;i++){
            if(s[i]=='a' && i>fidx){
                idx=i;
                break;   
            }
            if(i==0 && s[i]=='a')h=1;
        }
        
        if(idx==-1)
            idx=n;
        
        if(fidx==-1)
            fidx=0;
        
        cout<<fidx<<" "<<idx<<endl;
        for(int i=fidx;i<idx;i++){
            if(h && i==0)
                continue;
            
            s[i]--;
        }
        return s;
    }
};