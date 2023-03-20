class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        bool h=0;
        if(n==1 && f[0]==0 && f.size()==1)
        return 1;

        f.push_back(0);
        f.insert(f.begin(),0);

        for(int i=1;i<f.size()-1;i++){
            if(n==0)
            return 1;
            
            if(f[i+1]==0 && f[i]==0 && f[i-1]==0){
                f[i]=1;
                n--;
            }
        }
        return n==0;
    }
};