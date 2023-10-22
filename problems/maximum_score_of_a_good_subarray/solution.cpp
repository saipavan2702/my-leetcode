class Solution {
public:
    int maximumScore(vector<int>& L, int k) {
        int i = k, j = k;
        int curr = L[k];
        int ans = curr;

        while (i > 0 || j < L.size() - 1) {
            if (i == 0 || (j < L.size() - 1 && L[j + 1] > L[i - 1])) {
                j++;
            } else {
                i--;
            }
            curr = min(curr, min(L[i], L[j]));
            ans = max(ans, curr * (j - i + 1));
        }
        
        return ans;
    }
};