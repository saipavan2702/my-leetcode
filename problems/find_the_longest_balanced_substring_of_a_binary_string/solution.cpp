class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int n=size(s);
        int need = 0;
        for (int i=0;i<n;) {
            
            int zeros = 0;
            int ones = 0;
            
            while (i<n and s[i]=='0') {
                zeros++;
                i++;
            }
            while (i<n and s[i]=='1') {
                ones++;
                i++;
            }
            int len = 2 * min(zeros, ones);
            need = max(need, len);
        }
        return need;
    }
};