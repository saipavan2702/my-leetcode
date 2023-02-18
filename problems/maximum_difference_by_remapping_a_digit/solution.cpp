class Solution {
public:
    
    int minMaxDifference(int n) {
        
        string Max=to_string(n);
        string Min=to_string(n);
        
        int N=Max.size();
        char prev1=Max[0];
        char prev2=Max[0];
        
        int i=0;
        while(i<n) {
            if(Max[i]!='9'){
                prev1=Max[i];
                break;
            }
            i++;
        }
        
        
            for(int i=0;i<N;i++){
                if(Max[i]==prev1)
                    Max[i]='9';
            }
    
        for(int i=0;i<N;i++){
            if(Min[i]==prev2)
                Min[i]='0';
        }
       
        return stoi(Max)-stoi(Min);
        
    }
};