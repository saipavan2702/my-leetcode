class Solution {
public:
    int timeRequiredToBuy(vector<int>&t, int k) {
        int n;
        n=t.size();
        int sus=0;
        while(1)
        {
          for(int i=0;i<n;i++)
          {
            if(t[i]==0)
            continue;
            
            sus++;
            t[i]--;
            if(t[k]==0)
            return sus;
          }
        }
        
    }
};