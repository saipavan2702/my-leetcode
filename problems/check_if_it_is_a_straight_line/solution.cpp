class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& Pos) {
        int n=Pos.size();
        int slope;
        sort(Pos.begin(),Pos.end());

        for(int i=1;i<n;i++){
            if(i==1){
                if(Pos[i][0]!=Pos[i-1][0])
                slope=(Pos[i][1]-Pos[i-1][1])/(Pos[i][0]-Pos[i-1][0]);
                else
                slope=INT_MAX;
            }else{
                if(slope==INT_MAX){
                    if(Pos[i][0]!=Pos[i-1][0])
                    return 0;
                }
                else if(Pos[i][0]==Pos[i-1][0])
                return 0;
                else if(slope!=(Pos[i][1]-Pos[i-1][1])/(Pos[i][0]-Pos[i-1][0]))
                return 0;
            }
        }
        return 1;
    }
};