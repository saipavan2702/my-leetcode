class Solution {
public:
    bool exist(vector<vector<char>>& board, string s) {
        int n=board.size();
        int p=board[0].size();

        function<bool(int,int,string)>recur=[&](int x, int y, string have)->bool{
            if(have=="")return 1;
            if(x<0 or y<0 or x>=n or y>=p or board[x][y]!=have[0])return 0;

            char ch=board[x][y];
            board[x][y]='#';

            auto curr=have.substr(1);
            bool op1=recur(x+1,y,curr);
            bool op2=recur(x,y+1,curr);
            bool op3=recur(x-1,y,curr);
            bool op4=recur(x,y-1,curr);

            board[x][y]=ch;
            return op1 or op2 or op3 or op4;
        };
        
        for(int i=0;i<n;i++){
            for(int j=0;j<p;j++){
                if(board[i][j]==s[0] and recur(i,j,s))return 1;
            }
        }
        return 0;
    }
};