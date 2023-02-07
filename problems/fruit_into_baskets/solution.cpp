class Solution {
public:
    int totalFruit(vector<int>& F) {
        int n=F.size();
        unordered_map<int,int>freq;
        int len=0,j=0;
        for(int i=0;i<n;i++) {
            freq[F[i]]++;

            if(freq.size()<=2)
            len=max(len,i-j+1);
            else {
                freq[F[j]]--;
                
                if(freq[F[j]]==0)
                freq.erase(F[j]);

                j++;
            }
        }
        return len;
    }
};