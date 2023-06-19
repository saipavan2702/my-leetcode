class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int pref[105]={0};
        pref[0]=0;

        for(int i=0;i<gain.size();i++)
        pref[i+1]=pref[i]+gain[i];

        return *max_element(pref,pref+105);
    }
};