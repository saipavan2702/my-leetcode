class Solution {
public:
    int maximumBags(vector<int>&C, vector<int>&L, int R) {
        int n;
        n=C.size();

        for(int i=0;i<n;i++)
        C[i]=C[i]-L[i];

        sort(C.begin(),C.end());

        int cnt=0;
        for(int i:C) {
            if(i<=R) {
                R-=i;
                cnt++;
            }
            else break;
        }
        return cnt;

    }
};