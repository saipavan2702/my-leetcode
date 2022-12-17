class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int len=INT_MIN;
        for(auto&x:strs)
        {
            int cnt=0;
            bool flag=0;
            for(auto&y:x)
            {
                if(y>='a' and y<='z')
                    flag=1;
            }
            if(flag)
            cnt=x.size();
            else
            cnt=stoi(x);
            
            len=max(len,cnt);
        }
        return len;
    }
};