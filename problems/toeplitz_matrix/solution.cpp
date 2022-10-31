class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>&t) {
        int n,p;
        n=t.size();
        p=t[0].size();
        
        unordered_map<int,int>freq;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<p;j++)
            {
               if(freq.count(i-j))
               {
                   if(freq[i-j]!=t[i][j])
                       return 0;
               }
               freq[i-j]=t[i][j];
            }
        }
        return 1;
    }
};