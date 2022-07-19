class Solution {
public:
   
    vector<int> getRow(int l) {
        vector<int>res(l+1);
        res[0]=1;
        for(int i=1;i<=l;i++)
		{
          res[i]=(int)((long)res[i-1]*(l-i+1)/(i));
        }
        return res;
    }
};