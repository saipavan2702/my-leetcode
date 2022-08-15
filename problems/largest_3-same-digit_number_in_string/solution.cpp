class Solution {
public:
    string largestGoodInteger(string num) {
        int n;
        n=num.size();
        int cnt=-1;
        for(int i=1;i<n-1;i++)
        {
            if(num[i]==num[i-1] and num[i]==num[i+1])
            cnt=max(cnt,num[i]-'0');
        }
        return cnt!=-1?string(3,cnt+'0'):"";
    }
};