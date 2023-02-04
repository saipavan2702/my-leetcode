class Solution {
public:
    void spl(int n,vector<int>&an){
        int u=n,l=0;
        while(u!=0){
            u/=10;
            l++;
        }
        l--;
        while(l>=0) {
            int s=pow(10,l);
            int z=n/s;
            an.push_back(z);
            n-=z*s;
            l--;
        }
    }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>an;
        for(int &i:nums){
            spl(i,an);
        }
        return an;
    }
};