class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& C, int eC) {
        vector<bool>can;
        int l=*max_element(begin(C),end(C));

        int n=C.size();
        for(int i:C){
            if(i+eC>=l)
            can.push_back(1);
            else
            can.push_back(0);
        }
        return can;
    }
};