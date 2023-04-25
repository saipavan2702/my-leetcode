class Solution {
public:
    int findDelayedArrivalTime(int aT, int dT) {
        int s=aT+dT;
        return s%24;
    }
};