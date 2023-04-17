class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& T) {
        int n=T.size();
        int f,loc=0,idx=0;
        for(int i=0;i<n;i++){
            f=count(T[i].begin(),T[i].end(),1);
            if(f>loc)
                loc=f,idx=i;
        }
        
        return vector<int>({idx,loc});
    }
};