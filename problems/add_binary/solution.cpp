class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.size(),p=b.size();
        int i=n-1,j=p-1;

        string Q="";
        int Y=0;
        while(i>=0 || j>=0) {

           if(i>=0)
           Y+=(a[i--]=='1');

           if(j>=0)
           Y+=(b[j--]=='1');

           Q.push_back(Y%2+'0');
           Y/=2;
        }
        if(Y)
        Q.push_back('1');

        reverse(begin(Q),end(Q));
        return Q;
    }
};