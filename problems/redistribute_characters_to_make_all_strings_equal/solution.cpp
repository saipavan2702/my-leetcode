class Solution {
public:
    bool makeEqual(vector<string>& G) {
         unordered_map<char, int> counts;
        for (auto a:G) {
            for (char x : a) {
                counts[x]++;
            }
        }
        
        int n = G.size();
        for (auto a : counts) {
            if (a.second % n != 0) {
                return false;
            }
        }
        return true;
    }
};