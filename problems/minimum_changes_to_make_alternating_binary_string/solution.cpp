class Solution {
public:
    int minOperations(string s) {
        int op1 = count(s, s[0]);
        int op2 = count(s, s[0] == '0' ? '1' : '0') + 1;
        return min(op1, op2);
    }

private:
    int count(string s, char pre) {
        int count = 0;
        for (int i = 1; i < s.length(); i++) {
            char curr = s[i];
            if (curr == pre) {
                count++;
                pre = pre == '0' ? '1' : '0';
            } else {
                pre = curr;
            }
        }
        return count;
    }
};