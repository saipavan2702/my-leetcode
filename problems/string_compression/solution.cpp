class Solution {
public:
    int compress(vector<char>& ch) {
        string s="";
        int n=size(ch);
        int k=1;

        if(n==1)
        return 1;

        for(int i=0;i<n-1;i++){
            if(ch[i]==ch[i+1]){
                k++;
            }
            else{
                s+=ch[i];

                if(k!=1)
                s+=to_string(k);

                k=1;
            }
        }
        if(ch[n-2]!=ch[n-1])
        s+=ch[n-1];

        if(k!=1)
        s+=ch[n-1],s+=to_string(k);

        int len=size(s);

        int i=0;
        for(auto &x:s)
        ch[i]=x,i++;

        return len;
    }
};