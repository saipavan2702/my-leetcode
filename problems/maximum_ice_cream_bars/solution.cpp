class Solution {
public:
    int maxIceCream(vector<int>& T, int c) {
        int n=T.size();
        sort(T.begin(),T.end());
        int cnt=0;

        for(int i=0;i<n;i++){
            if(T[i]<=c){
                c-=T[i];
                cnt++;
            }
        }
        return cnt;
    }
};