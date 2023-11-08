class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int X=abs(sx-fx);
        int Y=abs(sy-fy);

        if(X==0 and Y==0) return t!=1;
        return X<=t and Y<=t?true:false;
    }
};