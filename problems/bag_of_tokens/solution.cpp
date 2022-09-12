class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score=0,n,ans=0;
        n=tokens.size();
        sort(tokens.begin(),tokens.end());
        int i=0,j=n-1;
        while(j>=i)
        {
            
            if(tokens[i]<=power)
            {
                power-=tokens[i];
                i++;
                score++;
                ans=max(ans,score);
            }
            else if(score>0)
            {
                power+=tokens[j];
                score--;
                j--;
            }
            else 
            break;
        }
        return ans;
        
    }
};