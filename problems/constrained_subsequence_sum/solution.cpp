class Solution {
public:
    int constrainedSubsetSum(vector<int>& N, int k) {
        deque<int> dq;
        for (int i = 0; i < N.size(); ++i) {
            N[i] += !dq.empty() ? N[dq.front()] : 0;
            while (!dq.empty() && (i - dq.front() >= k || N[i] >= N[dq.back()])) {
                if (N[i] >= N[dq.back()]) dq.pop_back();
                else dq.pop_front();
            }
            
            if (N[i] > 0) {
                dq.push_back(i);
            }
        }
        return *max_element(N.begin(), N.end());
    }
};