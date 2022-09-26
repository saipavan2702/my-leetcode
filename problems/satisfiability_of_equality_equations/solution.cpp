class Solution {
    int par[27];
    int R[27];
public:
    int find(int x){
        if(par[x] == x)
            return par[x] = x;
        return par[x] = find(par[x]);
    }
    
    void Union(int x, int y){
        if(R[x] < R[y]){
            R[y] += R[x];
            par[x] = y;
        }
        else{
            R[x] += R[y];
            par[y] = x;
        }
    }
    
    bool equationsPossible(vector<string>& equations) {
        for(int i = 0; i < 27; i++){
            par[i] = i;
            R[i] = 0;
        }
        
        for(string equation: equations){
            int a = find(equation[0] - 'a');
            int b = find(equation[3] - 'a');
            
            if(equation[1] == '=') Union(a, b);
        }
        
        for(string equation: equations){
            int a = find(equation[0] - 'a');
            int b = find(equation[3] - 'a');
            
            if(equation[1] == '!' && a == b){
                return false;
            }
        }
        
        return true;
    }
};