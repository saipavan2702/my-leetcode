class Solution {
public:
    bool digitCount(string num) {
        int i,n;
        n=num.size();
        map<int,int>freq;
        for(i=0;i<n;i++)
        {
            freq[num[i]-'0']++;
        }
        for(i=0;i<n;i++)
        {
            if(freq[i]!=num[i]-'0')
            {
                return false;
            }
        }
        return true;
        
    }
};