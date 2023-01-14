class Solution {
public:
    int find(int r,int P[]){
        if(P[r]==-1)
        return r;

        return find(P[r],P);
    }
    void uni(int u, int v, int P[]){
        if(u!=v){
            if(u>v)
            P[u]=v;
            else
            P[v]=u;
        }
    }
    string smallestEquivalentString(string s1, string s2, string b) {
        int n=s1.length();
        int P[26];
        for(int i=0;i<26;i++)
        P[i]=-1;

        for(int i=0;i<n;i++){
            int x=find(s1[i]-'a',P);
            int y=find(s2[i]-'a',P);
            uni(x,y,P);
        }
        for(int i=0;i<b.size();i++){
            b[i]=find(b[i]-'a',P)+'a';
        }
        return b;

    }
};