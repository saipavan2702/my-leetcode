class Solution {
public:
    vector<string> buildArray(vector<int>& T, int n) {
        vector<string> result;
        int curr = 1;

        for (int i = 0; i < T.size(); i++) {
            while (curr < T[i]) {
                result.push_back("Push");
                result.push_back("Pop");
                curr++;
            }
            result.push_back("Push");
            curr++;
        }
        return result;
    }
};