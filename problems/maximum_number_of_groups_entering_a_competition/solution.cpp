class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n;
        n=grades.size();
        return (int)(sqrt(1+8*n)-1)/2;
    }
};